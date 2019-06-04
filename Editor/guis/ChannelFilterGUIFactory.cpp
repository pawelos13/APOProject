/*
    This file is part of EqualizerAPO, a system-wide equalizer.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "Editor/FilterTable.h"
#include "ChannelFilterGUI.h"
#include "ChannelFilterGUIFactory.h"

ChannelFilterGUIFactory::ChannelFilterGUIFactory()
{
}

void ChannelFilterGUIFactory::initialize(FilterTable* filterTable)
{
	this->filterTable = filterTable;
}

QList<FilterTemplate> ChannelFilterGUIFactory::createFilterTemplates()
{
	QList<FilterTemplate> list;
	list.append(FilterTemplate(tr("Channel (Select channels)"), "Channel: all", QStringList(tr("Control"))));
	return list;
}

IFilterGUI* ChannelFilterGUIFactory::createFilterGUI(QString& command, QString& parameters)
{
	ChannelFilterGUI* result = NULL;

	if (command == "Channel")
	{
		result = new ChannelFilterGUI(parameters, filterTable->getSelectedChannelMask());
	}

	return result;
}
