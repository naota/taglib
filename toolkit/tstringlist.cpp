/***************************************************************************
    copyright            : (C) 2002, 2003 by Scott Wheeler
    email                : wheeler@kde.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
 *   USA                                                                   *
 ***************************************************************************/

#include "tstringlist.h"

using namespace TagLib;

class StringListPrivate
{

};

////////////////////////////////////////////////////////////////////////////////
// static members
////////////////////////////////////////////////////////////////////////////////

StringList StringList::split(const String &s, const String &pattern)
{
  StringList l;

  int previousOffset = 0;
  for(int offset = s.find(pattern); offset != -1; offset = s.find(pattern, offset + 1)) {
    l.append(s.substr(previousOffset, offset - previousOffset));
    previousOffset = offset + 1;
  }

  l.append(s.substr(previousOffset, s.size() - previousOffset));

  return l;
}

////////////////////////////////////////////////////////////////////////////////
// public members
////////////////////////////////////////////////////////////////////////////////

StringList::StringList() : List<String>()
{

}

StringList::StringList(const StringList &l) : List<String>(l)
{

}

StringList::StringList(const String &s) : List<String>()
{
  append(s);
}

StringList::~StringList()
{

}

String StringList::toString(const String &separator) const
{
  String s;

  ConstIterator it = begin();

  while(it != end()) {
    s += *it;
    it++;
    if(it != end())
      s += separator;
  }

  return s;
}

////////////////////////////////////////////////////////////////////////////////
// related functions
////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &s, const StringList &l)
{
  s << l.toString();
  return s;
}
