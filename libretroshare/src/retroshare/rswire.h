#ifndef RETROSHARE_WIRE_GUI_INTERFACE_H
#define RETROSHARE_WIRE_GUI_INTERFACE_H

/*
 * libretroshare/src/retroshare: rswire.h
 *
 * RetroShare C++ Interface.
 *
 * Copyright 2012-2012 by Robert Fernie.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License Version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA.
 *
 * Please report all bugs and problems to "retroshare@lunamutt.com".
 *
 */

#include <inttypes.h>
#include <string>
#include <list>

#include "retroshare/rstokenservice.h"
#include "retroshare/rsgxsifacehelper.h"


/* The Main Interface Class - for information about your Peers */
class RsWire;
extern RsWire *rsWire;

class RsWireGroup
{
	public:

	RsGroupMetaData mMeta;
	std::string mDescription;
};



/***********************************************************************
 * So pulses operate in the following modes.
 *
 * => Standard, a post to your own group.
 * => @User, gets duplicated on each user's group.
 * => RT, duplicated as child of original post.
 *
 * From Twitter: 
 *  twitter can be: embedded, replied to, favourited, unfavourited, 
 *    retweeted, unretweeted and deleted
 *
 * See: https://dev.twitter.com/docs/platform-objects
 *
 * Format of message: .... 
 *
 *  #HashTags.
 *  @68769381495134  => ID of Sender. 
 *  <http>
 *
 ***********************************************************************/

class RsWirePlace
{
	public:

	

};


class RsWirePulse
{
	public:

	RsMsgMetaData mMeta;

	std::string mPulseText; // all the text is stored here.
	std::string mHashTags; 

// These will be added at some point.
//	std::string mInReplyPulse;

//	uint32_t mPulseFlags;

//	std::list<std::string> mMentions;
//	std::list<std::string> mHashTags;
//	std::list<std::string> mUrls;

//	RsWirePlace mPlace;
};


std::ostream &operator<<(std::ostream &out, const RsWireGroup &group);
std::ostream &operator<<(std::ostream &out, const RsWirePulse &pulse);


class RsWire: public RsGxsIfaceHelper
{
	public:

	RsWire(RsGxsIface *gxs): RsGxsIfaceHelper(gxs)  { return; }
virtual ~RsWire() { return; }

	/* Specific Service Data */
virtual bool getGroupData(const uint32_t &token, std::vector<RsWireGroup> &groups) = 0;
virtual bool getPulseData(const uint32_t &token, std::vector<RsWirePulse> &pulses) = 0;

virtual bool createGroup(uint32_t &token, RsWireGroup &group) = 0;
virtual bool createPulse(uint32_t &token, RsWirePulse &pulse) = 0;

};

#endif
