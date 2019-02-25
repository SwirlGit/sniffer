#include "ConfigurationView.h"
#include "ConfigurationViewPrivate.h"

using ViewLayer::ConfigurationViewPrivate;
using ViewLayer::ConfigurationView;


ConfigurationViewPrivate::ConfigurationViewPrivate(QWidget* parent)
{
    Q_UNUSED(parent);
}


// ****

ConfigurationView::ConfigurationView(QWidget *parent) :
    QFrame(parent),
    m_pimpl(new ConfigurationViewPrivate(parent))
{
    setObjectName("configurationView");
}

ConfigurationView::~ConfigurationView()
{

}
