#include "objectwatchmodel.h"

using namespace JuliaPlugin;

ObjectWatchModel::ObjectWatchModel(QObject *parent) :
  QAbstractTableModel(parent)
{}

int ObjectWatchModel::rowCount(const QModelIndex &parent) const
{
  return names.count();
}

int ObjectWatchModel::columnCount(const QModelIndex &parent) const
{
  return 3;
}

QVariant ObjectWatchModel::data(const QModelIndex &index, int role) const
{
  if ( index.row() >= names.count() )
    return QVariant();

  if (role == Qt::DisplayRole)
  {
    int c = index.column();
    if ( c == 0 )
      return names.at(index.row()).module;
    else if ( c == 1 )
      return names.at(index.row()).name;
    else if ( c == 2 )
      return names.at(index.row()).type;
  }
  return QVariant();
}

QVariant ObjectWatchModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if ( orientation == Qt::Vertical )
    return QVariant();

  if ( role != Qt::DisplayRole )
    return QVariant();

  switch (section)
  {
    case 0:
      return tr( "Module" );
    case 1:
      return tr( "Name" );
    case 2:
      return tr( "Type" );
    default:
      return QVariant();
  }
}

void ObjectWatchModel::clear()
{
  names.clear();
}

void ObjectWatchModel::addobj( QString mod, QString name, QString type )
{
  names.append( ObjectWatchData( mod, name, type ) );
}

void ObjectWatchModel::display()
{
  beginResetModel();
  endResetModel();
}

