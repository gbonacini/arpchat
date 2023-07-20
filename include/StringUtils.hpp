// -----------------------------------------------------------------
// arplib - a library to send arbitrary ARP packets
// Copyright (C) 2023  Gabriele Bonacini
//
// This program is distributed under dual license:
// - Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0) License 
// for non commercial use, the license has the following terms:
// * Attribution — You must give appropriate credit, provide a link to the license, 
// and indicate if changes were made. You may do so in any reasonable manner, 
// but not in any way that suggests the licensor endorses you or your use.
// * NonCommercial — You must not use the material for commercial purposes.
// A copy of the license it's available to the following address:
// http://creativecommons.org/licenses/by-nc/4.0/
// - For commercial use a specific license is available contacting the author.
// -----------------------------------------------------------------

#pragma once

#include <exception>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <initializer_list>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#include <anyexcept.hpp>

namespace stringutils{ 

   std::string mergeStrings(std::initializer_list<const char*> list)   noexcept;

   class  StringUtilsException final : public std::exception {
           public:
                   explicit    StringUtilsException(int errNum);
                   explicit    StringUtilsException(std::string&  errString);
                   explicit    StringUtilsException(std::string&& errString);
                               StringUtilsException(int errNum, std::string& errString);
                               StringUtilsException(int errNum, std::string&& errString);
                   const char* what(void)                                                     const noexcept override;
                   int         getErrorCode(void)                                             const noexcept;

           private:
                   std::string errorMessage;
                   int errorCode;
   };

   template<class T, class T2>
   void      decodeB64(const T& in, T2& out)                                                        anyexcept;
   template<class T, class T2>
   void      encodeB64(const T& in, T2& out)                                                        anyexcept;

   extern template
   void   encodeB64(const std::vector<uint8_t>& in, std::string& out)                               anyexcept;
   extern template
   void   decodeB64(const std::string& in, std::vector<uint8_t>& out)                               anyexcept;

 }  // End namespace stringutils
