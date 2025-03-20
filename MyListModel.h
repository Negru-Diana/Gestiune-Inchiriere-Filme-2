#pragma once
#include "domain.h"
#include <QAbstractListModel>
#include <vector>
#include <string>
#include<qdebug.h>
using namespace std;

using std::vector;
class MyListModel :public QAbstractListModel 
{
private:
    vector<Film> all;


public:
    
    MyListModel(const vector<Film>& all) : all{ all } {}


    int rowCount(const QModelIndex& parent = QModelIndex()) const override 
    {
        return all.size();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override 
    {

        if (!index.isValid() || index.row() >= all.size()) {
            return QVariant{};
        }

        const Film& film = all[index.row()];

        if (role == Qt::DisplayRole) {
            // Echivalent pentru item->setText(QString::fromStdString(f.get_titlu()));
            return QString::fromStdString(film.get_titlu());
        }
        else if (role == Qt::UserRole) {
            // Echivalent pentru item->setData(Qt::UserRole, filmData);
            QVariant filmData;
            filmData.setValue(QString::fromStdString(film.get_gen()));
            return filmData;
        }
        return QVariant{};
    }

    void set(const vector<Film>& filme) 
    {
        //emit layoutAboutToBeChanged();
        all = filme;
        auto topIndex = createIndex(0, 0);
        auto botIndex = createIndex(rowCount(), 0);
        emit dataChanged(topIndex, botIndex);
        emit layoutChanged();

    }
};
