#include "ApplicationView.h"
#include "ApplicationViewPrivate.h"

#include <QStackedWidget>
#include <QTabBar>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>

using ViewLayer::ApplicationViewPrivate;
using ViewLayer::ApplicationView;


ApplicationViewPrivate::ApplicationViewPrivate() :
      tabs(new QTabBar),
      content(new QStackedWidget)
{
    tabs->setCursor(Qt::PointingHandCursor);
}


// ****

ApplicationView::ApplicationView(QWidget *parent)
    : QWidget(parent),
      m_pimpl(new ApplicationViewPrivate)
{
    setObjectName("applicationView");

    // Устанавливаем максимальную ширину виджетов приложения
    QDesktopWidget *desktop = QApplication::desktop();
    const int desktopMaximumWidth = desktop->availableGeometry().width();
    m_pimpl->tabs->setMaximumWidth(desktopMaximumWidth);
    m_pimpl->content->setMaximumWidth(desktopMaximumWidth);
    m_pimpl->tabs->setMaximumHeight(50);

    // Настраиваем представление
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSizeConstraint(QLayout::SetMaximumSize);
    layout->setContentsMargins(QMargins());
    layout->setSpacing(0);
    layout->addWidget(m_pimpl->tabs);
    layout->addWidget(m_pimpl->content);
    setLayout(layout);

    connect(m_pimpl->tabs, &QTabBar::currentChanged, m_pimpl->content, &QStackedWidget::setCurrentIndex);
}

ApplicationView::~ApplicationView()
{

}

void ApplicationView::addContentPage(const QString& pageName, QWidget* page)
{
    m_pimpl->tabs->addTab(pageName);
    m_pimpl->content->addWidget(page);
}

void ApplicationView::insertContentPage(int index, const QString& pageName, QWidget* page)
{
    m_pimpl->tabs->insertTab(index, pageName);
    m_pimpl->content->insertWidget(index, page);
}

void ApplicationView::removeContentPage(QWidget* page)
{
    const int pageIndex = m_pimpl->content->indexOf(page);
    if (m_pimpl->tabs->currentIndex() == pageIndex) {
        m_pimpl->tabs->setCurrentIndex(pageIndex);
    }

    m_pimpl->tabs->removeTab(pageIndex);
    m_pimpl->content->removeWidget(page);
}

int ApplicationView::currentContentPageIndex() const
{
    return m_pimpl->tabs->currentIndex();
}

QString ApplicationView::contentPageName(int index) const
{
    return m_pimpl->tabs->tabText(index);
}

void ApplicationView::setContentPageName(int index, const QString& name)
{
    m_pimpl->tabs->setTabText(index, name);
}

void ApplicationView::setCurrentContentPage(int index)
{
    m_pimpl->tabs->setCurrentIndex(index);
}
