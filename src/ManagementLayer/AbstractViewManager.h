#ifndef ABSTRACTVIEWMANAGER_H
#define ABSTRACTVIEWMANAGER_H

#include <QObject>

class QWidget;

namespace ManagementLayer
{
class AbstractViewManager : public QObject
{
public:
    explicit AbstractViewManager(QObject* parent = nullptr);

    /**
     * @brief Получить представление, которым управляет контроллер
     */
    virtual QWidget* view() const = 0;
};
}

#endif // ABSTRACTVIEWMANAGER_H
