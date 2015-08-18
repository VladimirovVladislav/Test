#include "myclient.h"

#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QTime>

// ====================================================================================
MyClient::MyClient (//
                    QWidget* pwgt
                    ): QWidget (pwgt)
                    , m_nNextBlockSize (0)
{
    qDebug() << "client constr";

    m_pTcpSocket = new QTcpSocket (this); // создаем объект сокета

    connect(m_pTcpSocket, SIGNAL(connected()),
            this, SLOT (slotConnected())); // отправляет как только будет установлено соединение

    connect(m_pTcpSocket, SIGNAL(readyRead()),
            this, SLOT (slotReadyRead())); // отправляет при готовности предоставить данные

    connect(m_pTcpSocket, SIGNAL (error(QAbstractSocket::SocketError)), // отправляет при возникновении ошибки
            this, SLOT(slotError(QAbstractSocket::SocketError))
            );

    qDebug() << "connecting...";
}

   void MyClient::connectToHost()
{

    m_pTcpSocket->connectToHost("localhost", 2323);

qDebug() << "connectToHost";

}

// ====================================================================================
void MyClient::connectToHost() {

   qDebug() << "connectToHost";

   m_pTcpSocket->connectToHost ("localhost", 2323);

   qDebug() << m_pTcpSocket->waitForConnected();
   qDebug() << m_pTcpSocket->waitForReadyRead();
}

// =====================================================================================

void MyClient::slotReadyRead() // слот, который вызывается при поступлении данных от сервера
{

   QDataStream in (m_pTcpSocket);
    in.setVersion(QDataStream::Qt_4_5);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (m_pTcpSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }
        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QTime time;
        QString str;
        in >> time >>str;

        //inforesults -> append(time.toString() + "" + str);

        qDebug() << "slotReady";

        emit clientInformation(time.toString() + "" + str);

        m_nNextBlockSize = 0;
    }
}

// =======================================================================================

void MyClient::slotError(QAbstractSocket::SocketError err) // слот, который вызывается при возникновении ошибок
{


    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                        "The host was not found." :
                        err == QAbstractSocket::RemoteHostClosedError ?
                        "The remote host is closed." :
                        err == QAbstractSocket::ConnectionRefusedError ?
                        "The connection was refused." :
                        QString (m_pTcpSocket->errorString())
                        );


    //inforesults->append(strError);

    qDebug() << "slotError";

    emit clientInformation(strError);

}

// =================================================================================================

void MyClient::slotSendToServer() // метод отсылки запросов серверу
{
    QByteArray arrBlock;
    QDataStream out (&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << QTime::currentTime() << InputInformation->text();

    out.device()->seek(0);
    out << quint16 (arrBlock.size() - sizeof(quint16));

    m_pTcpSocket->write(arrBlock);

    InputInformation->setText(" ");

    //emit clientInputInformation(InputInformation);

}

// ================================================================================================

void MyClient::slotConnected() // метод вызывается как только будет установлена связь
{
    //inforesults->append("Received the connected() signal");

    qDebug() << "slotConnected";

    emit clientInformation("Received the connected() signal");

}
// =================================================================================================

