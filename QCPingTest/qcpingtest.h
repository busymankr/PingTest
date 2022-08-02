#ifndef QCPINGTEST_H
#define QCPINGTEST_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class QCPingTest : public QObject
{
    Q_OBJECT
public:
    explicit QCPingTest(QObject *parent = nullptr);
    ~QCPingTest();

    /**
     * @brief start or stop
     * @param bStart : do ping or not
     * @return
     */
    int ping(bool bStart);

    /**
     * @brief setIP
     * @param ip
     */
    void setIP(QString ip);

    /**
     * @brief getIP
     * @return
     */
    QString getIP();

private:

    /**
     * @brief init
     * @return
     */
    int init();

    /**
     * @brief deinit
     * @return
     */
    int deinit();

    /**
     * @brief stop
     * @return
     */
    int stop();

    /**
     * @brief start
     * @return
     */
    int start();

    /**
     * @brief convToLineByLine
     * @param s :: output string
     * @return
     */
    QStringList convToLineByLine(QString s);

    /**
     * @brief getResponseTime
     * @param s : Response Time (String)
     * @return Response time (in microseconds)
     */
    qlonglong getResponseTime(QString s);

    /**
     * @brief isWinEnOutputString
     * @param s
     * @param r
     * @return
     */
    bool isWinEnOutputString(QString s, QString &r);

    /**
     * @brief isWinKrOutputString
     * @param s
     * @return
     */
    bool isWinKrOutputString(QString s, QString &r);

    /**
     * @brief isLinuxEnOutputString
     * @param s
     * @return
     */
    bool isLinuxEnOutputString(QString s, QString &r);

    /**
     * @brief checkOutputString
     * @param s
     * @return
     */
    bool checkOutputString(QString s, QString &r);

signals:
    void sigGetResponseTime(qlonglong us);

private slots:
    void readyReadStandardOutput();
    void processStarted();
    void processFinished();

private:
    QProcess *m_pProcessPing;
    QString m_OutputString;
    QString m_IP;

};

#endif // QCPINGTEST_H
