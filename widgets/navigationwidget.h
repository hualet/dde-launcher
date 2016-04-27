#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include "categorybutton.h"
#include "global_util/calculate_util.h"

#include <QWidget>
#include <QButtonGroup>

#include <dimagebutton.h>

DWIDGET_USE_NAMESPACE

class NavigationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationWidget(QWidget *parent = 0);

    void setButtonsVisible(const bool visible);
    void setCategoryTextVisible(const bool visible);
    QLabel *categoryTextLabel(const AppsListModel::AppCategory category) const;

signals:
    void scrollToCategory(const AppsListModel::AppCategory category) const;
    void mouseEntered();

public slots:
    void setCurrentCategory(const AppsListModel::AppCategory category);
    void refershCategoryVisible(const AppsListModel::AppCategory category, const int appNums);

protected:
    void enterEvent(QEvent *e);

private:
    void initUI();
    void initConnection();

    void buttonClicked();
    CategoryButton *button(const AppsListModel::AppCategory category) const;

private:
    CalculateUtil *m_calcUtil;
    QButtonGroup *m_categoryGroup;
    CategoryButton *m_internetBtn;
    CategoryButton* m_chatBtn;
    CategoryButton *m_musicBtn;
    CategoryButton *m_videoBtn;
    CategoryButton *m_graphicsBtn;
    CategoryButton *m_gameBtn;
    CategoryButton *m_officeBtn;
    CategoryButton *m_readingBtn;
    CategoryButton *m_developmentBtn;
    CategoryButton *m_systemBtn;
    CategoryButton *m_othersBtn;
};

#endif // NAVIGATIONWIDGET_H