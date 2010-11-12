/*
 * This file is part of phantom-drivers.
 *
 * phantom-drivers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * phantom-drivers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with phantom-drivers.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Phantom Library: FireWire communication driver for Mac OS X
 */

#include <string.h>

#include "FirewireDeviceMacOSX.h"
#include "CommunicationMacOSX.h"

using namespace LibPhantom;

FirewireDeviceMacOSX::FirewireDeviceMacOSX(IOFireWireLibDeviceRef interface) :
  interface(interface)
{
	com=createCommunication();
}


FirewireDeviceMacOSX::~FirewireDeviceMacOSX()
{
	delete com;
	(*interface)->Close(interface);

}


Communication * FirewireDeviceMacOSX::createCommunication() {
	return new CommunicationMacOSX(interface);
}

IOFireWireLibDeviceRef FirewireDeviceMacOSX::getInterface()
{
  return interface;
}

unsigned int FirewireDeviceMacOSX::getFreeChannel() {
	throw "Not implemented";
}

void FirewireDeviceMacOSX::claimChannel(unsigned int channel) {
	throw "Not implemented";
}
void FirewireDeviceMacOSX::releaseChannel(unsigned int channel) {
	throw "Not implemented";
}

