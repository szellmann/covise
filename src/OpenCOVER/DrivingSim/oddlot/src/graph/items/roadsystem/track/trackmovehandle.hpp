/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/**************************************************************************
** ODD: OpenDRIVE Designer
**   Frank Naegele (c) 2010
**   <mail@f-naegele.de>
**   20.04.2010
**
**************************************************************************/

#ifndef TRACKLINKHANDLE_HPP
#define TRACKLINKHANDLE_HPP

#include "src/graph/items/handles/movehandle.hpp"

class TrackEditor;
class TrackComponent;

class TrackMoveHandle : public MoveHandle
{

    //################//
    // FUNCTIONS      //
    //################//

public:
    explicit TrackMoveHandle(TrackEditor *trackEditor, QGraphicsItem *parent);
    virtual ~TrackMoveHandle();

    void registerLowSlot(TrackComponent *trackComponent);
    void registerHighSlot(TrackComponent *trackComponent);

    int getPosDOF() const
    {
        return posDOF_;
    }
    double getPosDOFHeading() const
    {
        return posDOFHeading_;
    }
    TrackComponent *getLowSlot() const
    {
        return lowSlot_;
    }
    TrackComponent *getHighSlot() const
    {
        return highSlot_;
    }

    // Observer Pattern //
    //
    virtual void updateObserver();

protected:
private:
    TrackMoveHandle(); /* not allowed */
    TrackMoveHandle(const TrackMoveHandle &); /* not allowed */

    void updateDOF();
    int calculatePosDOF();
    void updateColor();

    //################//
    // EVENTS         //
    //################//

protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    //################//
    // PROPERTIES     //
    //################//

protected:
private:
    TrackEditor *trackEditor_;

    TrackComponent *lowSlot_;
    TrackComponent *highSlot_;

    int posDOF_;
    double posDOFHeading_;
};

#endif // TRACKLINKHANDLE_HPP
