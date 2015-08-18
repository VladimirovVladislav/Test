#include <QtWidgets>
#include <QtNetwork>

#include "client.h"

Client::Client(QWidget *parent)
:   QDialog(parent), networkSession(0)
{
// ======================================================================================================
// Создание окна запроса на соединение


    hostLabel = new QLabel(tr("&Server name:"));
    portLabel = new QLabel(tr("S&erver port:"));

    hostCombo = new QComboBox;
    hostCombo->setEditable(true);

    // find out name of this machine
    // узнать имя этого аппарата

    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QString("localhost"))
        hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    // add localhost addresses
    // добавить локальный адреса

    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    hostLabel->setBuddy(hostCombo);
    portLabel->setBuddy(portLineEdit);


    statusLabel = new QLabel(tr("Введите параметры подключения и нажмите Get Fortune. "));

    QString peremennaiyStatusLabel ("Проверка параметров подключения.");

    qDebug () << "GGGGGGGGG";

    emit clientInformation(peremennaiyStatusLabel);

    getFortuneButton = new QPushButton(tr("Get Fortune"));
    getFortuneButton->setDefault(true);
    getFortuneButton->setEnabled(false);

    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(getFortuneButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

// ====================================================================================================
    // создание соединения

    tcpSocket = new QTcpSocket(this);

    connect(hostCombo, SIGNAL(editTextChanged(QString)),
            this, SLOT(enableGetFortuneButton())
            );

    connect(portLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableGetFortuneButton())
            );

    connect(getFortuneButton, SIGNAL(clicked()), // подключение нажатием на кнопку get fortune
            this, SLOT(requestNewFortune())
            );

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close())  // закрытие окна нажатием на Quit
            );

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readFortune())
            );

    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError))
            );


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostCombo, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Fortune Client"));
    portLineEdit->setFocus();

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {

        // Получение сохраненной конфигурации сети

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // Если сохраненная конфигурация сети в настоящее время не обнаружена, использовать систему по умолчанию

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);

        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened())
                );

        getFortuneButton->setEnabled(false);
        statusLabel->setText(tr("Opening network session."));

        networkSession->open();
    }
}

// =================================================================================================================

void Client::requestNewFortune()
{
    getFortuneButton->setEnabled(false);
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(),
                             portLineEdit->text().toInt());

        if(tcpSocket->waitForConnected()) // putting 1 as parameter isn't reasonable, using default 3000ms value
        {
            QString string = "Hello";
            QByteArray array;
            array.append(string);

            qDebug()<< string;
        }
        else
        {
            qDebug() << "couldn't connect";
        }
}

// =====================================================================================================================

void Client::readFortune()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    QString nextFortune;
    in >> nextFortune;

    if (nextFortune == currentFortune) {
        QTimer::singleShot(0, this, SLOT(requestNewFortune()));
        return;
    }

    currentFortune = nextFortune;
    statusLabel->setText(currentFortune);
    getFortuneButton->setEnabled(true);
}

//======================================================================================================

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr(" Хост не найден. Пожалуйста, проверьте имя и параметры хост-порта. "));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    getFortuneButton->setEnabled(true);
}

// ======================================================================================================

void Client::enableGetFortuneButton()
{
    getFortuneButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 !hostCombo->currentText().isEmpty() &&
                                 !portLineEdit->text().isEmpty());

}

// =======================================================================================================

void Client::sessionOpened()
{
    // Сохранить используемую конфигурацию

    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

    statusLabel->setText(tr("This examples requires that you run the "
                            "Fortune Server example as well."));

    enableGetFortuneButton();
}
