/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /projects/kabuki/igeek/library/igeek_geneticpolygonpanel.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-19 Cale McCollough <cale@astartup.net>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#include "cgeneticpolygonpanel.h"

namespace kabuki {
namespace igeek {

GeneticPolygonPanel::GeneticPolygonPanel (GeneticPolygon thisShape, String thisShapeLabel, SI4 width, SI4 height)
{
  setPreferredSize (new Dimension (width, height));
  setBorder (BorderFactory.createLineBorder (Color.BLACK));
  setLayout (new BorderLayout ());

  JLabel thisLabel = new JLabel (thisShapeLabel);
  add (thisLabel, BorderLayout.NORTH);

  gPoly = thisShape;
}

void GeneticPolygonPanel::paintComponent (Graphics g)
{
  super.paintComponent (g);

  SI4 offsetX, offsetY;

  // We want to center the GeneticPolygon

  Dimension panelDimensions = getPreferredSize ();

  if (gPoly != null)
  {
    offsetX = (panelDimensions.width - gPoly.Width ()) / 2;
    offsetY = (panelDimensions.height - gPoly.Height ()) / 2;

    g.drawImage (gPoly.getBitmap (), offsetX, offsetY, null);
  }
}

GeneticPolygonPanel::GeneticPolygon getGeneticPolygon ()
{
  return gPoly;
}

void GeneticPolygonPanel::respawn (SI4 numPoints, SI4 width, SI4 height, SI4 color, SI4 lifespan, FP8 angle)
{
  gPoly = new GeneticPolygon (numPoints, width, height, color, lifespan, angle);
}

void GeneticPolygonPanel::setGeneticPolygon (GeneticPolygon newPoly)
{
  gPoly = newPoly;
}

}
}
