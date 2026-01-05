#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Hunspell/hunspell.hxx>
#include <QDir>
#include <QFile>
using namespace std;

// Carefully crafted example that works with hunspell and qt strings
// TLDR; mostly its stops working, so dont change any variable or add new intermediate variable
// like
// GOOD:
//  const char * hunspell_str = word.toStdString().c_str();
// BAD: (this will not work)
//  auto stdStr = word.toStdString();
//  const char * hunspell_str = stdStr.c_str();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString basePath = "C:/Users/admin/Documents/hunspell-demo";
    QString affPath = basePath + "/en_US.aff";
    QString dictPath = basePath + "/en_US.dic";

    qDebug() << affPath;
    qDebug() << dictPath;

    // Check if files exist
    qDebug() << "AFF exists:" << QFile::exists(affPath);
    qDebug() << "DIC exists:" << QFile::exists(dictPath);

    // Convert to local 8-bit encoding (important for file paths on Windows)
    std::string affstdstr = affPath.toStdString();
    std::string dictstdstr = affPath.toStdString();

    const char * aff_c_str = affstdstr.c_str();
    const char * dict_c_str = dictstdstr.c_str();

    // Now create Hunspell with persistent data
    Hunspell h(aff_c_str, dict_c_str);

    QStringList l = {"hello", "world" , "test", "gkfjgkdfjgkdj", "xyzabc"};
    // Test with multiple known words
    for (QString &word : l) {
        const char * hunspell_str = word.toStdString().c_str();
        qDebug() << "spell " << word << ":" << h.spell(hunspell_str);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
