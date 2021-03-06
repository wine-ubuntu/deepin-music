/*
 * Copyright (C) 2016 ~ 2018 Wuhan Deepin Technology Co., Ltd.
 *
 * Author:     Iceyer <me@iceyer.net>
 *
 * Maintainer: Iceyer <me@iceyer.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <DSearchEdit>

#include "../core/playlist.h"

class SearchResult;
class SearchEdit : public Dtk::Widget::DSearchEdit
{
    Q_OBJECT
public:
    explicit SearchEdit(QWidget *parent = Q_NULLPTR);

    PlaylistPtr curPlaylistPtr()
    {
        return playlist;
    }

public:
    void setResultWidget(SearchResult *);

signals:
    void searchText(const QString &id, const QString &text);
    void searchCand (const QString &text);
    void locateMusic(const QString &hash);

public slots:
    void onFocusIn();
    void onFocusOut();
    void onTextChanged();
    void onReturnPressed();

protected:
    virtual void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private:
    void searchText2(QString id, QString text);
    void searchText3(QString id, QString text);
    SearchResult    *m_result = nullptr;
    PlaylistPtr      playlist = nullptr;
    QString         m_CurrentId;
    QString         m_Text;
    QString         m_LastText;
};
