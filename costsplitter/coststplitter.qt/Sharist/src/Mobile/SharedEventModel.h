#ifndef SHAREDEVENTMODEL_H
#define SHAREDEVENTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "ExpenseItemListModel.h"
#include "SharedEvent.h"

class SharedEventModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(ExpenseItemListModel *expenseList READ expenseList NOTIFY expenseListChanged)
private:
    SharedEvent* rawSharedEvent;
    ExpenseItemListModel* expensesListModel;
public:
    SharedEventModel(QObject *parent = 0);
    SharedEventModel(SharedEvent* rawSharedEvent);
    QString name() const;
    ExpenseItemListModel* expenseList();
signals:
    void expenseListChanged();
    void nameChanged();
};

#endif // SHAREDEVENTMODEL_H
