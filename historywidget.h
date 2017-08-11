#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QWidget>
#include <QListView>
#include <QPushButton>

class HistoryModel;
class HistoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWidget(QWidget *parent = 0);

private slots:
    void onItemClicked(const QModelIndex &index);

private:
    HistoryModel *m_historyModel;
    QListView *m_historyView;
    QPushButton *m_clearBtn;
};

#endif // HISTORYWIDGET_H