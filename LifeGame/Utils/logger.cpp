#include "logger.h"

#include <QDateTime>
#include <QDir>

std::unique_ptr<QFile> Logger::logFile = Q_NULLPTR;
bool Logger::isInit = false;

QHash<QtMsgType, QString> Logger::contextNames = {
    {QtMsgType::QtDebugMsg,		" Debug  "},
    {QtMsgType::QtInfoMsg,		"  Info  "},
    {QtMsgType::QtWarningMsg,	"Warning "},
    {QtMsgType::QtCriticalMsg,	"Critical"},
    {QtMsgType::QtFatalMsg,		" Fatal  "}
};

void Logger::init(QString file) {
    if (isInit)
        return;

    logFile = std::make_unique<QFile>();
    logFile->setFileName(file);
    logFile->open(QIODevice::Append | QIODevice::Text);

    // redirect logs to file
    qInstallMessageHandler(Logger::messageOutput);

    logFile->resize(0);

    Logger::isInit = true;
}

void Logger::clean() {
    if (logFile != Q_NULLPTR) {
        logFile->close();
        logFile = Q_NULLPTR;
    }
}

void Logger::messageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg) {

    QString log = QObject::tr("%1 | %2 | %3:%4:%5 | %6\n").
        arg(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")).
        arg(Logger::contextNames.value(type)).
        arg(QString(context.file).
            section('\\', -1)).			// File name without file path
        arg(QString(context.function).
            section('(', -2, -2).		// Function name only
            section(' ', -1).
            section(':', -1)).
            arg(context.line).
        arg(msg);

    logFile->write(log.toLocal8Bit());
    logFile->flush();
}
