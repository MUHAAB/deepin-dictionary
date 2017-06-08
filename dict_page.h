#ifndef DICTPAGE_H
#define DICTPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class DictPage : public QWidget
{
    Q_OBJECT

public:
    DictPage(QWidget *parent = 0);

    void queryWord(const QString &word);

    QNetworkAccessManager *http;

    QVBoxLayout *layout;
    QHBoxLayout *wordLayout;
    QHBoxLayout *pronLayout;
    QHBoxLayout *infoLayout;
    QLabel *nameLabel;
    QLabel *ukPron;
    QLabel *usPron;
    QLabel *infoLabel;


private slots:
    void replyfinished(QNetworkReply *reply);
};

#endif // DICTPAGE_H
