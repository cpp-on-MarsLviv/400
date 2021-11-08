#ifndef LOGGER_H
#define LOGGER_H

#include "Helpers/constants.h"

#include <QHash>

#include <memory>

class QFile;

/**
 * @brief The Logger class
 */
class Logger {
private:
    /// @brief The file where logs are written to.
    static std::unique_ptr<QFile> logFile;

    /// @brief Whether the logger has being initialized.
    static bool isInit;

    /// @brief The different types of context.
    static QHash<QtMsgType, QString> contextNames;

public:
    Logger() = delete;

    /// @brief Initializes the logger.
    static void init(QString file = Helpers::appLogfileDefault);

    /// @brief Cleans up the logger.
    static void clean();

    /// @brief The function which handles the logging of text.
    static void messageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};

#endif // LOGGER_H
