<div align="center">

# These are full license terms for

$\color{gold}\Huge{\textsf{STM32CubeEval}}$

Copyright © 2023 Stephan Linz

**No warranty, no guarantee, no liability or conditions of any kind.**

This is a derivation work from [STM32CubeF7], Copyright © 2021 STMicroelectronics.

All rights reserved

[![ST logo](/_htmresc/st_logo_2020.png)](https://www.st.com)

</div>

## <mark>__STATUS__</mark>

$\color{#58A6FF}\textsf{\Large\&#x24D8;\kern{0.2cm}\normalsize Note}$
$\color{gold}\large{\textsf{WORK IN PROGRESS}}$

$\color{#D29922}\textsf{\Large\&#x26A0;\kern{0.2cm}\normalsize Warning}$
$\color{gold}\large{\textsf{NOT INTENDED FOR PRODUCTION DEVELOPMENT}}$

## <mark>__Important__</mark> - Read carefully

### FEES

All components can be used free of charge as long as the use is for
evaluation purposes only.

### PROPRIETARY RIGHTS

Title, ownership rights, and intellectual property rights in the product
shall remain by applicable copyright holders and/or their suppliers.
Licensee acknowledges such ownership and intellectual property rights and
will not take any action to jeopardize, limit or interfere in any manner
with applicable Licensors or its suppliers' ownership of or rights with
respect to the product. The product or product names are protected by
copyright and other intellectual property laws and by international
treaties. Title and related rights in the content accessed throughthe
product is the property of the applicable content owner and is protected
by applicable law. The Licenses granted under this agreement gives
Licensee no rights to suchcontent.

### DISCLAIMER OF WARRANTY

The product is provided on an “as is” basis, without warranty of any kind,
including without limitation the warranties that it is free of defects,
merchantable, fit for a particular purpose or non-infringing. The entire
risk as to the quality and performance of the product is borne by Licensee.
Should the product prove defective in any respect, Licensee and not Licensor
or its suppliers or resellers assumes the entire cost of any service and
repair. In addition, the security mechanisms implemented by theproduct
have inherent limitations, and Licensee must determine that the product
sufficiently meets its requirements. This disclaimer of warranty constitutes
an essentialpart of this agreement. No use of the product is authorized
hereunder except under this disclaimer.

### LIMITATION OF LIABILITY

To the maximum extent permitted by applicable law, in no event will Licensor
or its suppliers or resellers be liable for any indirect, special, incidental
or consequential damages arising out of the use of or inability to use the
product, including, without limitation, damages for loss of goodwill, work
stoppage, computer failure or malfunction, or any and all other commercial
damages or losses, even if advised of the possibility thereof, and regardless
of the legal or equitable theory (contract, tort orotherwise) upon which the
claim is based. In any case, Licensor's entire liability under any provision
of this agreement shall not exceed in the aggregate the sum of thefees Licensee
paid for this license (if any), with the exception of death or personal injury
caused by the negligence of Licensor to the extent applicable law prohibits
the limitation of damages in such cases. Some jurisdictions do not allow the
exclusion or limitation of incidental or consequential damages, so this
exclusion and limitation may not be applicable. Respective copyright holders
are not responsible for any liability arising out of content provided by
Licensee or a third party that is accessed through the product and/or any
material linked through such content.

### HIGH RISK ACTIVITIES

The product is not fault-tolerant and is not designed, manufactured or intended
for use or resale as on-line control equipment in hazardous environments
requiring fail-safe performance, such as in the operation of nuclear facilities,
aircraft navigation or communication systems, air traffic control, direct life
support machines, or weapons systems, in which the failure of the product could
lead directly to death, personal injury, or severe physical or environmental
damage (“High Risk Activities”). Accordingly, applicable content owners,
copyright holders, applicable Licensor and its suppliers specifically disclaim
any express or implied warranty of fitness for High Risk Activities. Licensee
agrees that applicable Licensor and its suppliers will not be liable for any
claims or damages arising from the use of the product in such applications.

## <mark>__OVERVIEW__</mark>

This Software Bill Of Material (SBOM) lists the software components of this
software package, including the copyright owner and license terms for each
component.

The full text of these licenses are below the SBOM.

__SOFTWARE BILL OF MATERIALS__

| Component                       | Copyright                                                  | License                                   |
|:---------                       |:----------                                                 |:-------                                   |
| CMSIS                           | Copyright © 2009-2017 [ARM] Limited. All rights reserved.  | [Apache-2.0]                              |
| CMSIS Device                    | [ARM] Limited - [STMicroelectronics]                       | [Apache-2.0]                              |
| STM32F7 HAL                     | [STMicroelectronics]                                       | [BSD-3-Clause]                            |
| BSP STM32F723E-Discovery        | [STMicroelectronics]                                       | [BSD-3-Clause]                            |
| BSP STM32F769I-Discovery        | [STMicroelectronics]                                       | [BSD-3-Clause]                            |
| BSP STM32F7308-Discovery        | [STMicroelectronics]                                       | [BSD-3-Clause]                            |
| BSP Components                  | [STMicroelectronics]                                       | [BSD-3-Clause]                            |
| BSP Adafruit                    | [STMicroelectronics]                                       | [BSD-3-Clause]                            |
| [FreeRTOS kernel]               | Copyright © 2017 [Amazon.com][AWS], Inc. or its affiliates | [MIT]                                     |
| [LwIP]                          | [Swedish Institute of Computer Science][SICS]              | [BSD-3-Clause]                            |
| [MbedTLS]                       | [ARM] Limited - [STMicroelectronics]                       | [Apache-2.0]                              |
| [FatFS]                         | [ChaN] - [STMicroelectronics]                              | [BSD-3-Clause]                            |
| [LibJPEG]                       | [Thomas G. Lane], Guido Vollbeding                         | [Independent JPEG Group License][IJG]     |
| STM32 USB Device Library        | [STMicroelectronics]                                       | [SLA] (SLA0044)                           |
| STM32 USB Host Library          | [STMicroelectronics]                                       | [SLA] (SLA0044)                           |
| STM32 Audio                     | [STMicroelectronics]                                       | [SLA] (SLA0048, from STM32CubeFW)         |
| [STemWin]                       | [STMicroelectronics] - [SEGGER Microcontroller GmbH]       | [SLA] (SLA0048, from STM32CubeFW)         |
| [TouchGFX]                      | [STMicroelectronics]                                       | [SLA] (SLA0044)                           |
| STM32 Projects                  | [STMicroelectronics]                                       | [SLA] ([BSD-3-Clause] for basic Examples) |
| STM32 Utilities                 | [STMicroelectronics]                                       | [BSD-3-Clause]                            |

[Apache-2.0]: #al2
[BSD-3-Clause]: #bsd3
[MIT]: #mit
[IJG]: #ijg
[SLA]: #sla

[AWS]: https://aws.amazon.com/freertos
[FreeRTOS kernel]: https://www.freertos.org/kernel/license.html

[SICS]: http://www.sics.se/
[LwIP]: http://lwip.wikia.com/wiki/License

[ARM]: https://www.arm.com/
[MbedTLS]: https://tls.mbed.org/kb/licensing

[ChaN]: http://elm-chan.org/
[FatFS]: http://elm-chan.org/fsw/ff/doc/appnote.html#license

[Thomas G. Lane]: https://en.wikipedia.org/wiki/Tom_Lane_(computer_scientist)
[LibJPEG]: https://www.ijg.org/

[SEGGER Microcontroller GmbH]: https://www.segger.com/
[STMicroelectronics]: https://www.st.com/
[STemWin]: https://www.st.com/en/embedded-software/stemwin.html
[TouchGFX]: https://www.st.com/en/embedded-software/x-cube-touchgfx.html
[STM32CubeF7]: https://www.st.com/STM32CubeF7

### SLA – STMicroelectronics’ “Ultimate Liberty License”

*“… it’s an anti-open-source poison pill license under the guise
of an “ultimate liberty” license …"*, read more here:

* ST Community: [License talk]
* ST Community: [Ultimate Liberty license - what is allowed?]
* [The (Arduino Portenta H7) software isn't fully open-source either.], see:
  https://github.com/stm32duino/Arduino_Core_STM32/blob/main/License.md
* [The STM32 USB libraries are provided under the oddly named …]
* [Open sourcing code using SLA0044 libraries]
* [That makes this software non-free.]

[License talk]: https://community.st.com/t5/stm32-mcus-products/license-talk/m-p/273540
[Ultimate Liberty license - what is allowed?]: https://community.st.com/t5/stm32-mcus-embedded-software/ultimate-liberty-license-what-is-allowed/td-p/245950
[The (Arduino Portenta H7) software isn't fully open-source either.]: https://news.ycombinator.com/item?id=27766066#27766436
[The STM32 USB libraries are provided under the oddly named …]: https://news.ycombinator.com/item?id=22775357
[Open sourcing code using SLA0044 libraries]: https://opensource.stackexchange.com/questions/12169
[That makes this software non-free.]: https://lists.debian.org/debian-legal/2015/04/msg00023.html



<!----><a name="al2"></a>
<details>
  <summary><b>Apache-2.0 – Apache License, Version 2.0</b> <i>(click me)</i></summary>

[Apache-2.0](https://opensource.org/licenses/Apache-2.0) February 8, 2004

<!----><a name="collapse-al2"></a>
## Apache License

_Version 2.0, January 2004_  
_&lt;<http://www.apache.org/licenses/>&gt;_

### Terms and Conditions for use, reproduction, and distribution

#### 1. Definitions

“License” shall mean the terms and conditions for use, reproduction, and
distribution as defined by Sections 1 through 9 of this document.

“Licensor” shall mean the copyright owner or entity authorized by the copyright
owner that is granting the License.

“Legal Entity” shall mean the union of the acting entity and all other entities
that control, are controlled by, or are under common control with that entity.
For the purposes of this definition, “control” means **(i)** the power, direct or
indirect, to cause the direction or management of such entity, whether by
contract or otherwise, or **(ii)** ownership of fifty percent (50%) or more of the
outstanding shares, or **(iii)** beneficial ownership of such entity.

“You” (or “Your”) shall mean an individual or Legal Entity exercising
permissions granted by this License.

“Source” form shall mean the preferred form for making modifications, including
but not limited to software source code, documentation source, and configuration
files.

“Object” form shall mean any form resulting from mechanical transformation or
translation of a Source form, including but not limited to compiled object code,
generated documentation, and conversions to other media types.

“Work” shall mean the work of authorship, whether in Source or Object form, made
available under the License, as indicated by a copyright notice that is included
in or attached to the work (an example is provided in the Appendix below).

“Derivative Works” shall mean any work, whether in Source or Object form, that
is based on (or derived from) the Work and for which the editorial revisions,
annotations, elaborations, or other modifications represent, as a whole, an
original work of authorship. For the purposes of this License, Derivative Works
shall not include works that remain separable from, or merely link (or bind by
name) to the interfaces of, the Work and Derivative Works thereof.

“Contribution” shall mean any work of authorship, including the original version
of the Work and any modifications or additions to that Work or Derivative Works
thereof, that is intentionally submitted to Licensor for inclusion in the Work
by the copyright owner or by an individual or Legal Entity authorized to submit
on behalf of the copyright owner. For the purposes of this definition,
“submitted” means any form of electronic, verbal, or written communication sent
to the Licensor or its representatives, including but not limited to
communication on electronic mailing lists, source code control systems, and
issue tracking systems that are managed by, or on behalf of, the Licensor for
the purpose of discussing and improving the Work, but excluding communication
that is conspicuously marked or otherwise designated in writing by the copyright
owner as “Not a Contribution.”

“Contributor” shall mean Licensor and any individual or Legal Entity on behalf
of whom a Contribution has been received by Licensor and subsequently
incorporated within the Work.

#### 2. Grant of Copyright License

Subject to the terms and conditions of this License, each Contributor hereby
grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free,
irrevocable copyright license to reproduce, prepare Derivative Works of,
publicly display, publicly perform, sublicense, and distribute the Work and such
Derivative Works in Source or Object form.

#### 3. Grant of Patent License

Subject to the terms and conditions of this License, each Contributor hereby
grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free,
irrevocable (except as stated in this section) patent license to make, have
made, use, offer to sell, sell, import, and otherwise transfer the Work, where
such license applies only to those patent claims licensable by such Contributor
that are necessarily infringed by their Contribution(s) alone or by combination
of their Contribution(s) with the Work to which such Contribution(s) was
submitted. If You institute patent litigation against any entity (including a
cross-claim or counterclaim in a lawsuit) alleging that the Work or a
Contribution incorporated within the Work constitutes direct or contributory
patent infringement, then any patent licenses granted to You under this License
for that Work shall terminate as of the date such litigation is filed.

#### 4. Redistribution

You may reproduce and distribute copies of the Work or Derivative Works thereof
in any medium, with or without modifications, and in Source or Object form,
provided that You meet the following conditions:

* **(a)** You must give any other recipients of the Work or Derivative Works a copy of
this License; and
* **(b)** You must cause any modified files to carry prominent notices stating that You
changed the files; and
* **(c)** You must retain, in the Source form of any Derivative Works that You distribute,
all copyright, patent, trademark, and attribution notices from the Source form
of the Work, excluding those notices that do not pertain to any part of the
Derivative Works; and
* **(d)** If the Work includes a “NOTICE” text file as part of its distribution, then any
Derivative Works that You distribute must include a readable copy of the
attribution notices contained within such NOTICE file, excluding those notices
that do not pertain to any part of the Derivative Works, in at least one of the
following places: within a NOTICE text file distributed as part of the
Derivative Works; within the Source form or documentation, if provided along
with the Derivative Works; or, within a display generated by the Derivative
Works, if and wherever such third-party notices normally appear. The contents of
the NOTICE file are for informational purposes only and do not modify the
License. You may add Your own attribution notices within Derivative Works that
You distribute, alongside or as an addendum to the NOTICE text from the Work,
provided that such additional attribution notices cannot be construed as
modifying the License.

You may add Your own copyright statement to Your modifications and may provide
additional or different license terms and conditions for use, reproduction, or
distribution of Your modifications, or for any such Derivative Works as a whole,
provided Your use, reproduction, and distribution of the Work otherwise complies
with the conditions stated in this License.

#### 5. Submission of Contributions

Unless You explicitly state otherwise, any Contribution intentionally submitted
for inclusion in the Work by You to the Licensor shall be under the terms and
conditions of this License, without any additional terms or conditions.
Notwithstanding the above, nothing herein shall supersede or modify the terms of
any separate license agreement you may have executed with Licensor regarding
such Contributions.

#### 6. Trademarks

This License does not grant permission to use the trade names, trademarks,
service marks, or product names of the Licensor, except as required for
reasonable and customary use in describing the origin of the Work and
reproducing the content of the NOTICE file.

#### 7. Disclaimer of Warranty

Unless required by applicable law or agreed to in writing, Licensor provides the
Work (and each Contributor provides its Contributions) on an “AS IS” BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
including, without limitation, any warranties or conditions of TITLE,
NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A PARTICULAR PURPOSE. You are
solely responsible for determining the appropriateness of using or
redistributing the Work and assume any risks associated with Your exercise of
permissions under this License.

#### 8. Limitation of Liability

In no event and under no legal theory, whether in tort (including negligence),
contract, or otherwise, unless required by applicable law (such as deliberate
and grossly negligent acts) or agreed to in writing, shall any Contributor be
liable to You for damages, including any direct, indirect, special, incidental,
or consequential damages of any character arising as a result of this License or
out of the use or inability to use the Work (including but not limited to
damages for loss of goodwill, work stoppage, computer failure or malfunction, or
any and all other commercial damages or losses), even if such Contributor has
been advised of the possibility of such damages.

#### 9. Accepting Warranty or Additional Liability

While redistributing the Work or Derivative Works thereof, You may choose to
offer, and charge a fee for, acceptance of support, warranty, indemnity, or
other liability obligations and/or rights consistent with this License. However,
in accepting such obligations, You may act only on Your own behalf and on Your
sole responsibility, not on behalf of any other Contributor, and only if You
agree to indemnify, defend, and hold each Contributor harmless for any liability
incurred by, or claims asserted against, such Contributor by reason of your
accepting any such warranty or additional liability.

_END OF TERMS AND CONDITIONS_

### APPENDIX: How to apply the Apache License to your work

To apply the Apache License to your work, attach the following boilerplate
notice, with the fields enclosed by brackets `[]` replaced with your own
identifying information. (Don't include the brackets!) The text should be
enclosed in the appropriate comment syntax for the file format. We also
recommend that a file or class name and description of purpose be included on
the same “printed page” as the copyright notice for easier identification within
third-party archives.

    Copyright [yyyy] [name of copyright owner]

    Licensed under the Apache License, Version 2.0 (the “License”);
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an “AS IS” BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and

</details>




<!----><a name="bsd3"></a>
<details>
  <summary><b>BSD-3-Clause – The 3-Clause BSD License</b> <i>(click me)</i></summary>

[BSD-3-Clause](https://opensource.org/licenses/BSD-3-Clause)
*Note: This license has also been called the “New BSD License” or
       “Modified BSD License”.<br/>See also the [2-clause BSD License].*

[2-clause BSD License]: https://opensource.org/license/BSD-2-clause

<!----><a name="collapse-bsd3"></a>
## Modified BSD License

_Copyright © `<year>`, `<copyright holder>`_  
_All rights reserved._

**FatFs**: _Copyright © 2015, ChaN._  
**FatFs**: _Copyright © 2017, STMicroelectronics._  

**LwIP**: _Copyright © 2001-2004, Swedish Institute of Computer Science._  

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of the `<organization>` nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL `<COPYRIGHT HOLDER>` BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

</details>




<!----><a name="mit"></a>
<details>
  <summary><b>MIT – The MIT License</b> <i>(click me)</i></summary>

[MIT](https://opensource.org/licenses/MIT)

<!----><a name="collapse-mit"></a>
## The MIT License (MIT)

Copyright © `<year>` `<copyright holders>`

**FreeRTOS kernel**: _Copyright © 2017 Amazon.com, Inc. or its affiliates._  

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the “Software”), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

</details>




<!----><a name="ijg"></a>
<details>
  <summary><b>IJG – The Independent JPEG Group License</b> <i>(click me)</i></summary>

[IJG](https://spdx.org/licenses/IJG.html)

<!----><a name="collapse-ijg"></a>
## Independent JPEG Group License

LEGAL ISSUES

In plain English:

1. We don't promise that this software works.
   (But if you find any bugs, please let us know!)
2. You can use this software for whatever you want.
   You don't have to pay us.
3. You may not pretend that you wrote this software.
   If you use it in a program, you must acknowledge
   somewhere in your documentation that you've used
   the IJG code.

In legalese:

The authors make NO WARRANTY or representation, either express or
implied, with respect to this software, its quality, accuracy,
merchantability, or fitness for a particular purpose. This software
is provided “AS IS”, and you, its user, assume the entire risk as
to its quality and accuracy.

This software is copyright © 1991-2012, Thomas G. Lane, Guido Vollbeding.
All Rights Reserved except as specified below.

Permission is hereby granted to use, copy, modify, and distribute
this software (or portions thereof) for any purpose, without fee,
subject to these conditions:

* **(1)** If any part of the source code for this software is
          distributed, then this README file must be included,
          with this copyright and no-warranty notice unaltered;
          and any additions, deletions, or changes to the
          original files must be clearly indicated in
          accompanying documentation.

* **(2)** If only executable code is distributed, then the
          accompanying documentation must state that “this software
          is based in part on the work of the Independent JPEG Group”.

* **(3)** Permission for use of this software is granted only if
          the user accepts full responsibility for any undesirable
          consequences; the authors accept NO LIABILITY for damages
          of any kind.

These conditions apply to any software derived from or based on the
IJG code, not just to the unmodified library. If you use our work,
you ought to acknowledge us.

Permission is NOT granted for the use of any IJG author's name or
company name in advertising or publicity relating to this software or
products derived from it. This software may be referred to only as
“the Independent JPEG Group's software”.

We specifically permit and encourage the use of this software as the
basis of commercial products, provided that all warranty or liability
claims are assumed by the product vendor.

`ansi2knr.c` is included in this distribution by permission of L. Peter Deutsch,
sole proprietor of its copyright holder, Aladdin Enterprises of Menlo Park, CA.
`ansi2knr.c` is NOT covered by the above copyright and conditions, but instead
by the usual distribution terms of the Free Software Foundation; principally,
that you must include source code if you redistribute it. (See the file
`ansi2knr.c` for full details.) However, since `ansi2knr.c` is not needed
as part of any program generated from the IJG code, this does not limit you
more than the foregoing paragraphs do.

The Unix configuration script “`configure`” was produced with GNU Autoconf.
It is copyright by the Free Software Foundation but is freely distributable.
The same holds for its supporting scripts (`config.guess`, `config.sub`,
`ltconfig`, `ltmain.sh`). Another support script, `install-sh`, is copyright
by M.I.T. but is also freely distributable.

It appears that the arithmetic coding option of the JPEG spec is covered by
patents owned by IBM, AT&T, and Mitsubishi. Hence arithmetic coding cannot
legally be used without obtaining one or more licenses. For this reason,
support for arithmetic coding has been removed from the free JPEG software.
(Since arithmetic coding provides only a marginal gain over the unpatented
Huffman mode, it is unlikely that very many implementations will support it.)
So far as we are aware, there are no patent restrictions on the remaining code.

The IJG distribution formerly included code to read and write GIF files.
To avoid entanglement with the Unisys LZW patent, GIF reading support has
been removed altogether, and the GIF writer has been simplified to produce
“uncompressed GIFs”. This technique does not use the LZW algorithm; the
resulting GIF files are larger than usual, but are readable by all standard
GIF decoders.

We are required to state that “The Graphics Interchange Format © is the
Copyright property of CompuServe Incorporated. GIF℠ is a Service Mark
property of CompuServe Incorporated.”

</details>





<!----><a name="sla"></a>
<details>
  <summary><b>SLA – Software License Agreement</b> <i>(click me)</i></summary>

[SLA0044](https://www.st.com/SLA0044) Rev5/February 2018
[SLA0048](https://www.st.com/SLA0048) Rev4/March 2018

<!----><a name="collapse-sla"></a>
## Software license agreement

<!----><a name="collapse-sla0044"></a>
### __SLA0044 – ULTIMATE LIBERTY SOFTWARE LICENSE AGREEMENT__

BY INSTALLING COPYING, DOWNLOADING, ACCESSING OR OTHERWISE USING THIS SOFTWARE
OR ANY PART THEREOF (AND THE RELATED DOCUMENTATION) FROM STMICROELECTRONICS
INTERNATIONAL N.V, SWISS BRANCH AND/OR ITS AFFILIATED COMPANIES
(STMICROELECTRONICS), THE RECIPIENT, ON BEHALF OF HIMSELF OR HERSELF,
OR ON BEHALF OF ANY ENTITY BY WHICH SUCH RECIPIENT IS EMPLOYED AND/OR
ENGAGED AGREES TO BE BOUND BY THIS SOFTWARE LICENSE AGREEMENT.

Under STMicroelectronics’ intellectual property rights, the redistribution,
reproduction and use in source and binary forms of the software or any part
thereof, with or without modification, are permitted provided that the
following conditions are met:

1. Redistribution of source code (modified or not) must retain any copyright
   notice, this list of conditions and the disclaimer set forth below as
   items 10 and 11.

2. Redistributions in binary form, except as embedded into microcontroller
   or microprocessor device manufactured by or for STMicroelectronics or a
   software update for such device, must reproduce any copyright notice
   provided with the binary code, this list of conditions, and the disclaimer
   set forth below as items 10 and 11, in documentation and/or other materials
   provided with the distribution.

3. Neither the name of STMicroelectronics nor the names of other contributors
   to this software may be used to endorse or promote products derived from
   this software or part thereof without specific written permission.

4. This software or any part thereof, including modifications and/or derivative
   works of this software, must be used and execute solely and exclusively on
   or in combination with a microcontroller or microprocessor device
   manufactured by or for STMicroelectronics.

5. No use, reproduction or redistribution of this software partially or totally
   may be done in any manner that would subject this software to any Open Source
   Terms. “Open Source Terms” shall mean any open source license which requires
   as part of distribution of software that the source code of such software is
   distributed therewith or otherwise made available, or open source license
   that substantially complies with the Open Source definition specified at
   www.opensource.org and any other comparable open source license such as
   for example GNU General Public License (GPL), Eclipse Public License (EPL),
   Apache Software License, BSD license or MIT license.

6. STMicroelectronics has no obligation to provide any maintenance, support
   or updates for the software.

7. The software is and will remain the exclusive property of STMicroelectronics
   and its licensors. The recipient will not take any action that jeopardizes
   STMicroelectronics and its licensors' proprietary rights or acquire any
   rights in the software, except the limited rights specified hereunder.

8. The recipient shall comply with all applicable laws and regulations affecting
   the use of the software or any part thereof including any applicable export
   control law or regulation.

9. Redistribution and use of this software or any part thereof other than as
   permitted under this license is void and will automatically terminate your
   rights under this license.

10. THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS “AS IS”
    AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
    PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY RIGHTS,
    WHICH ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
    SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

11. EXCEPT AS EXPRESSLY PERMITTED HEREUNDER, NO LICENSE OR OTHER RIGHTS,
    WHETHER EXPRESS OR IMPLIED, ARE GRANTED UNDER ANY PATENT OR OTHER
    INTELLECTUAL PROPERTY RIGHTS OF STMICROELECTRONICS OR ANY THIRD PARTY.

<!----><a name="collapse-sla0048"></a>
### __SLA0048 – SOFTWARE PACKAGE LICENSE AGREEMENT__

BY INSTALLING COPYING, DOWNLOADING, ACCESSING OR OTHERWISE USING THIS SOFTWARE
PACKAGE OR ANY PART THEREOF (AND THE RELATED DOCUMENTATION) FROM
STMICROELECTRONICS INTERNATIONAL N.V, SWISS BRANCH AND/OR ITS AFFILIATED
COMPANIES (STMICROELECTRONICS), THE RECIPIENT, ON BEHALF OF HIMSELF OR HERSELF,
OR ON BEHALF OF ANY ENTITY BY WHICH SUCH RECIPIENT IS EMPLOYED AND/OR ENGAGED
AGREES TO BE BOUND BY THIS SOFTWARE PACKAGE LICENSE AGREEMENT.

Under STMicroelectronics’ intellectual property rights and subject to
applicable licensing terms for any third-party software incorporated in this
software package and applicable Open Source Terms (as defined here below),
the redistribution, reproduction and use in source and binary forms of the
software package or any part thereof, with or without modification, are
permitted provided that the following conditions are met:

1. Redistribution of source code (modified or not) must retain any copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form, except as embedded into microcontroller
   or microprocessor device manufactured by or for STMicroelectronics or a
   software update for such device, must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of STMicroelectronics nor the names of other contributors
   to this software package may be used to endorse or promote products
   derived from this software package or part thereof without specific
   written permission.

4. This software package or any part thereof, including modifications and/or
   derivative works of this software package, must be used and execute
   solely and exclusively on or in combination with a microcontroller
   or a microprocessor devices manufactured by or for STMicroelectronics.

5. No use, reproduction or redistribution of this software package partially
   or totally may be done in any manner that would subject this software
   package to any Open Source Terms (as defined below).

6. Some portion of the software package may contain software subject to
   Open Source Terms (as defined below) applicable for each such portion
   (“Open Source Software”), as further specified in the software package.
   Such Open Source Software is supplied under the applicable Open Source
   Terms and is not subject to the terms and conditions of license hereunder.
   “Open Source Terms” shall mean any open source license which requires
   as part of distribution of software that the source code of such software
   is distributed therewith or otherwise made available, or open source
   license that substantially complies with the Open Source definition
   specified at www.opensource.org and any other comparable open source
   license such as for example GNU General Public License (GPL), Eclipse
   Public License (EPL), Apache Software License, BSD license and MIT license.

7. This software package may also include third party software as expressly
   specified in the software package subject to specific license terms from
   such third parties. Such third party software is supplied under such
   specific license terms and is not subject to the terms and conditions
   of license hereunder. By installing copying, downloading, accessing or
   otherwise using this software package, the recipient agrees to be bound
   by such license terms with regard to such third party software.

8. STMicroelectronics has no obligation to provide any maintenance, support
   or updates for the software package.

9. The software package is and will remain the exclusive property of
   STMicroelectronics and its licensors. The recipient will not take
   any action that jeopardizes STMicroelectronics and its licensors'
   proprietary rights or acquire any rights in the software package,
   except the limited rights specified hereunder.

10. The recipient shall comply with all applicable laws and regulations
    affecting the use of the software package or any part thereof including
    any applicable export control law or regulation.

11. Redistribution and use of this software package partially or any part
    thereof other than as permitted under this license is void and will
    automatically terminate your rights under this license.

THIS SOFTWARE PACKAGE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS
“AS IS” AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT
NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE
PACKAGE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

EXCEPT AS EXPRESSLY PERMITTED HEREUNDER AND SUBJECT TO THE APPLICABLE LICENSING
TERMS FOR ANY THIRD-PARTY SOFTWARE INCORPORATED IN THE SOFTWARE PACKAGE AND
OPEN SOURCE TERMS AS APPLICABLE, NO LICENSE OR OTHER RIGHTS, WHETHER EXPRESS
OR IMPLIED, ARE GRANTED UNDER ANY PATENT OR OTHER INTELLECTUAL PROPERTY RIGHTS
OF STMICROELECTRONICS OR ANY THIRD PARTY.

</details>
