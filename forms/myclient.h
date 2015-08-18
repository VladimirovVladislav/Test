#ifndef MYCLIENT_H
#define MYCLIENT_H


#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>


class MyClient : public QWidget {
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket; // объявляем атрибут, необходимый для управления клиентом
    quint16 m_nNextBlockSize; // объявляем атрибут, необходимый для хранения длины следующего полученного от сокета блока

    QTextEdit* inforesults;    // объявляем атрибут, необходимый для отображения
    QLineEdit* InputInformation;   // объявляем атрибут, необходимый для ввода информации


public:
    explicit MyClient (QObject *parent = 0);
    void connectToHost(QString host, int port);
    void doConnect();

public slots:

    void connectToHost             (                            );

    void onSokConnected();
    void onSokDisconnected();

    void slotReadyRead             (                            );
    void slotError                 (QAbstractSocket::SocketError);
    void slotSendToServer          (                            );
    void slotConnected             (                            );

signals:
    void clientInformation(QString);
    void clientInputInformation(QString);

};

#endif // MYCLIENT_H
