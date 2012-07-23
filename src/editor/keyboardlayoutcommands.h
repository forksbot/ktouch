/*
 *  Copyright 2012  Sebastian Gottfried <sebastiangottfried@web.de>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEYBOARDLAYOUTCOMMANDS_H
#define KEYBOARDLAYOUTCOMMANDS_H

#include <QUndoStack>
#include <QRect>

class KeyboardLayout;

class SetKeyboardLayoutTitleCommand : public QUndoCommand
{
public:
    explicit SetKeyboardLayoutTitleCommand(KeyboardLayout* layout, const QString& newTitle, QUndoCommand* parent = 0);
    void undo();
    void redo();
    int id() const;
    bool mergeWith(const QUndoCommand* other);
private:
    KeyboardLayout* m_layout;
    QString m_oldTitle;
    QString m_newTitle;
};

class SetKeyboardLayoutNameCommand : public QUndoCommand
{
public:
    explicit SetKeyboardLayoutNameCommand(KeyboardLayout* layout, const QString& newName, QUndoCommand* parent = 0);
    void undo();
    void redo();
    int id() const;
    bool mergeWith(const QUndoCommand* other);
private:
    KeyboardLayout* m_layout;
    QString m_oldName;
    QString m_newName;
};

class SetKeyboardLayoutSizeCommand : public QUndoCommand
{
public:
    explicit SetKeyboardLayoutSizeCommand(KeyboardLayout* layout, const QSize& newSize, QUndoCommand* parent = 0);
    void undo();
    void redo();
    int id() const;
    bool mergeWith(const QUndoCommand* other);
private:
    KeyboardLayout* m_layout;
    QSize m_oldSize;
    QSize m_newSize;
};

class SetKeyGeometryCommand : public QUndoCommand
{
public:
    explicit SetKeyGeometryCommand(KeyboardLayout* layout, int keyIndex, const QRect& newRect, QUndoCommand* parent = 0);
    void undo();
    void redo();
    int id() const;
    bool mergeWith(const QUndoCommand* other);
private:
    KeyboardLayout* m_layout;
    int m_keyIndex;
    QRect m_oldRect;
    QRect m_newRect;
};

#endif // KEYBOARDLAYOUTCOMMANDS_H
