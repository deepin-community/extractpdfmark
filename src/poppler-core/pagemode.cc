// This file is part of Extract PDFmark.
//
// Copyright (C) 2016 Masamichi Hosoda
//
// Extract PDFmark is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Extract PDFmark is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Extract PDFmark.  If not, see <http://www.gnu.org/licenses/>.

#include "config.h"

#include "poppler-core.hh"

#include <sstream>
#include <PDFDoc.h>

std::string poppler_core::pagemode (void)
{
  std::stringstream ss;
  Catalog *catalog = doc->getCatalog ();

  if (catalog && catalog->isOk ())
    {
      switch (catalog->getPageMode ())
        {
        case Catalog::pageModeOutlines:
          ss << "[ /PageMode /UseOutlines /DOCVIEW pdfmark" << std::endl;
          break;
        case Catalog::pageModeThumbs:
          ss << "[ /PageMode /UseThumbs /DOCVIEW pdfmark" << std::endl;
          break;
        case Catalog::pageModeFullScreen:
          ss << "[ /PageMode /FullScreen /DOCVIEW pdfmark" << std::endl;
          break;
        case Catalog::pageModeOC:
          ss << "% pageModeOC" << std::endl;
          break;
        case Catalog::pageModeAttach:
          ss << "% pageModeAttach" << std::endl;
          break;
        case Catalog::pageModeNone:
        default:
          ss << "[ /PageMode /UseNone /DOCVIEW pdfmark" << std::endl;
          break;
        }
    }
  else
    ss << "% PageMode unset" << std::endl;

  return ss.str ();
}
