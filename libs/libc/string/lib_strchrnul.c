/****************************************************************************
 * libs/libc/string/lib_strchrnul.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <string.h>

#include "libc.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strchrnul
 *
 * Description:
 *   The strchrnul() function locates the first occurrence of 'c' (converted
 *   to a char) in the string pointed to by 's'. The terminating null byte is
 *   considered to be part of the string.
 *
 * Returned Value:
 *   Upon completion, strchrnul() returns a pointer to the byte, or a
 *   pointer to null if the byte was not found.
 *
 ****************************************************************************/

#if !defined(CONFIG_LIBC_ARCH_STRCHRNUL) && defined(LIBC_BUILD_STRCHRNUL)
#undef strchrnul /* See mm/README.txt */
FAR char *strchrnul(FAR const char *s, int c)
{
#ifdef CONFIG_LIBC_STRING_OPTIMIZE
  FAR char *s1 = strchr(s, c);

  return s1 ? s1 : (FAR char *)s + strlen(s);
#else
  if (s)
    {
      while (*s != '\0' && *s != c)
        {
          s++;
        }
    }

  return (FAR char *)s;
#endif
}
#endif
