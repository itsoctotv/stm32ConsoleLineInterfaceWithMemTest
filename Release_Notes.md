<div align="center">

# Release Notes for

$\color{gold}\Huge{\textsf{STM32CubeEval}}$

Copyright © 2023 Stephan Linz

**No warranty, no guarantee, no liability or conditions of any kind.**

This is a derivation work from [STM32CubeF7], Copyright © 2017 STMicroelectronics.

All rights reserved

[![ST logo](/_htmresc/st_logo_2020.png)](https://www.st.com)

</div>

## <mark>__STATUS__</mark>

$\color{#58A6FF}\textsf{\Large\&#x24D8;\kern{0.2cm}\normalsize Note}$
$\color{gold}\large{\textsf{WORK IN PROGRESS}}$

$\color{#D29922}\textsf{\Large\&#x26A0;\kern{0.2cm}\normalsize Warning}$
$\color{gold}\large{\textsf{NOT INTENDED FOR PRODUCTION DEVELOPMENT}}$

### Some middleware libraries are unavailable along with this repository

In this repository, the middleware libraries listed below **along with** the
projects (demos, applications, and examples) using them, are **not available
to the public** as they (the middleware libraries) are subject to some
restrictive license terms requiring the user's approval via a "click thru"
procedure:

* `./Middlewares/ST/STM32_Audio`
* `./Middlewares/ST/STemWin`
* `./Middlewares/ST/TouchGFX`

If needed, they can be found inside the full firmware package available on
STMicroelectronics website `st.com` and downloadable from [here][STM32CubeFW].
You will be prompted to login or to register in case you have no account.

## <mark>__PURPOSE__</mark>

**STM32CubeEval is an effort to reconstruct the original [STM32Cube] Firmware
Packages using modern development tools and make them ready for headless builds
on common CI/CD infrastructures without [STM32CubeIDE].**

**Only [STM32CubeCLT] will be needed for compilation. But, you can still use
the [STM32CubeIDE] for this "STM32 CMake project".**

[STM32Cube]: https://www.st.com/STM32Cube
[STM32CubeFW]: https://www.st.com/STM32CubeFW
[STM32CubeF7]: https://www.st.com/STM32CubeF7
[STM32CubeIDE]: https://www.st.com/STM32CubeIDE
[STM32CubeCLT]: https://www.st.com/STM32CubeCLT

**STM32CubeEval** covers also the STM32 portfolio and includes:

* A comprehensive embedded software platform, delivered per series
  (such as [STM32CubeF7] for STM32F7 series).
* The [STM32Cube] HAL, an STM32 abstraction layer embedded software,
  ensuring maximized portability across STM32 portfolio.
* A consistent set of middleware components such as RTOS, USB, TCP/IP,
  Graphics, FatFS.
* All embedded software utilities come with a full set of examples.
* The **[STM32Cube] firmware solution here in STM32CubeEval** offers
  the same straightforward API with a modular architecture, making it
  simple to fine tune custom applications and scalable to **fit most
  requirements on evaluation level or for proof-of-concept phases**.

  [![STM32Cube](/_htmresc/STM32Cube.bmp)](/_htmresc/STM32Cube.bmp)

* Below **links to the most useful releases and examples**.

  - [STM32CubeF7][STM32CubeF7-FWP]: Projects of Firmware Package
  - [STM32CubeF7][STM32CubeF7-FWE]: Firmware Examples
  - [Latest release][STM32CubeFW] of [STM32CubeF7] Firmware Package.
  - [32F723EDISCOVERY]: Discovery kit with STM32F723IE MCU.
  - [STM32F7308-DK]: Discovery kit with STM32F730I8 MCU.
  - [32F746GDISCOVERY]: Discovery kit with STM32F746NG MCU.
  - [STM32F7508-DK]: Discovery kit with STM32F750N8 MCU.
  - [STM32756G-EVAL]: Evaluation board with STM32F756NG MCU.
  - [32F769IDISCOVERY]: Discovery kit with STM32F769NI MCU.
  - [STM32F769I-EVAL]: Evaluation board with STM32F769NI MCU.

  [![STM32Cube components](/_htmresc/STM32Cube_components.bmp)](/_htmresc/STM32Cube_components.bmp)

[STM32CubeF7-FWP]: https://htmlpreview.github.io/?https://raw.githubusercontent.com/STMicroelectronics/STM32CubeF7/v1.17.1/Projects/Release_Notes.html
[STM32CubeF7-FWE]: https://htmlpreview.github.io/?https://raw.githubusercontent.com/STMicroelectronics/STM32CubeF7/v1.17.1/Projects/STM32CubeProjectsList.html
[32F723EDISCOVERY]: https://www.st.com/en/evaluation-tools/32f723ediscovery.html
[STM32F7308-DK]: https://www.st.com/en/evaluation-tools/stm32f7308-dk.html
[32F746GDISCOVERY]: https://www.st.com/en/evaluation-tools/32f746gdiscovery.html
[STM32F7508-DK]: https://www.st.com/en/evaluation-tools/stm32f7508-dk.html
[STM32756G-EVAL]: https://www.st.com/en/evaluation-tools/stm32756g-eval.html
[32F769IDISCOVERY]: https://www.st.com/en/evaluation-tools/32f769idiscovery.html
[STM32F769I-EVAL]: https://www.st.com/en/evaluation-tools/stm32f769i-eval.html

* Below **links to the most useful documents**.

  - [UM1891]: Getting started with STM32CubeF7 for STM32F7 Series.
  - [UM1905]: Description of STM32F7xx HAL drivers.
  - [UM1906]: STM32CubeF7 demonstration platform.
  - [UM2739]: How to enhance STM32CubeMX using STM32 Pack Creator tool.
  - [UM2388]: Development guidelines for STM32Cube Firmware Packs.
  - [UM2285]: Development guidelines for STM32Cube Expansion Packages.
  - [UM2312]: Development checklist for STM32Cube Expansion Packages.
  - [UM2298]: STM32Cube BSP drivers development guidelines.
  - [UM1720]: STM32Cube USB device library.
  - [UM1734]: STM32Cube USB host library.
  - [UM1709]: STM32Cube Ethernet IAP example.
  - [UM1723]: STM32Cube PolarSSL example.
  - [UM2372]: STM32Cube PDM2PCM software library for the STM32F4/F7/H7 Series.
  - [UM1721]: Developing Applications on STM32Cube with FatFs.
  - [UM1722]: Developing Applications on STM32Cube with RTOS.
  - [UM1713]: Developing Applications on STM32Cube with LwIP TCP/IP stack.
  - [UM1718]: STM32CubeMX for STM32 configuration and initialization C code generation.
  - [UM3088]: STM32CubeCLT (command-line toolset) quick start guide.
  - [UM3089]: STM32CubeCLT installation guide.
  - [UM2609]: STM32CubeIDE user guide.
  - [UM2576]: STM32CubeIDE ST-LINK GDB server.
  - [AN5952]: How to use CMake in STM32CubeIDE
  - [AN4989]: STM32 microcontroller debug toolbox.
  - [AN5156]: Introduction to STM32 microcontrollers security.
  - [TN1235]: Overview of ST-LINK derivatives.
  - [UM1075]: ST-LINK/V2 in-circuit debugger/programmer for STM8 and STM32.
  - [UM2448]: STLINK-V3SET in-circuit debugger/programmer for STM8 and STM32.
  - [UM2910]: STLINK-V3MINIE debugger/programmer tiny probe for STM8 and STM32.
  - [UM2502]: STLINK-V3MODS and STLINK-V3MINI debugger/programmer tiny probe for STM32.
  - [UM0892]: STM32 ST-LINK utility software description.

[UM1891]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00180213.pdf "Getting started with STM32CubeF7 for STM32F7 Series."
[UM1906]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00190393.pdf "STM32CubeF7 demonstration platform."
[UM1905]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00189702.pdf "Description of STM32F7xx HAL drivers."
[UM2739]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00716911.pdf "How to create a software pack enhanced for STM32CubeMX using STM32 Pack Creator tool."
[UM2388]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00488260.pdf "Development guidelines for STM32Cube Firmware Packs."
[UM2285]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00432311.pdf "Development guidelines for STM32Cube Expansion Packs."
[UM2312]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00447523.pdf "Development checklist for STM32Cube Expansion Packages."
[UM2298]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00440740.pdf "STM32Cube BSP drivers development guidelines."
[UM1720]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00105256.pdf "STM32Cube USB device library."
[UM1734]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00108129.pdf "STM32Cube USB host library."
[UM1709]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00103145.pdf "STM32Cube Ethernet IAP example."
[UM1723]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00105446.pdf "STM32Cube PolarSSL example."
[UM2372]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00482421.pdf "STM32Cube PDM2PCM software library for the STM32F4/F7/H7 Series."
[UM1721]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00105259.pdf "Developing Applications on STM32Cube with FatFs."
[UM1722]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00105262.pdf "Developing Applications on STM32Cube with RTOS."
[UM1713]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00103685.pdf "Developing Applications on STM32Cube with LwIP TCP/IP stack."
[UM1718]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00104712.pdf "STM32CubeMX for STM32 configuration and initialization C code generation."
[UM3088]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00915660.pdf "STM32Cube command-line toolset quick start guide."
[UM3089]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00915661.pdf "STM32CubeCLT installation guide."
[UM2609]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00629856.pdf "STM32CubeIDE user guide."
[UM2576]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00613038.pdf "STM32CubeIDE ST-LINK GDB server."
[AN5952]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/DM00965631.pdf "How to use CMake in STM32CubeIDE"
[AN4989]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/DM00354244.pdf "STM32 microcontroller debug toolbox."
[AN5156]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/DM00493651.pdf "Introduction to STM32 microcontrollers security."
[TN1235]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/technical_note/DM00290229.pdf "Overview of ST-LINK derivatives."
[UM1075]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00026748.pdf "ST-LINK/V2 in-circuit debugger/programmer for STM8 and STM32."
[UM2448]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00526767.pdf "STLINK-V3SET in-circuit debugger/programmer for STM8 and STM32."
[UM2910]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00813040.pdf "STLINK-V3MINIE debugger/programmer tiny probe for STM8 and STM32."
[UM2502]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00555046.pdf "STLINK-V3MODS and STLINK-V3MINI debugger/programmer tiny probe for STM32."
[UM0892]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/CD00262073.pdf "STM32 ST-LINK utility software description."

* Below **links to the most useful online references**.

  - [STM32 Education](https://www.st.com/content/st_com/en/support/learning/stm32-education.html)
  - [STM32 MCU wiki](https://wiki.st.com/stm32mcu)
  - [STM32 MCU SbS](https://wiki.st.com/stm32mcu/wiki/STM32StepByStep:STM32_step_by_step_overview):
    Step-by-Step
  - [STM32 MOOCs](https://www.st.com/content/st_com/en/support/learning/stm32-education/stm32-moocs.html):
    Massive Open Online Courses
  - [STM32 Text Books](https://www.st.com/content/st_com/en/support/learning/stm32-education/text-books.html)

## <mark>__CONTENT__</mark>

<div align="center">

### Drivers

| Name                                        | Version  | Date             | Release note                                 |
| :---                                        | :-----:  | :---             | :-----------                                 |
| [CMSIS]                                     | V5.4_CM7 | 22-March-2018    | [release notes][CMSIS-RN]                    |
| [STM32F7xx CMSIS]                           | V1.2.8   | 29-April-2022    | [release notes][STM32F7xx CMSIS-RN]          |
| [STM32F7xx HAL]                             | V1.3.0   | 10-June-2022     | [release notes][STM32F7xx HAL-RN]            |
| [BSP STM32F723E-Discovery]                  | V1.0.3   | 10-June-2022     | [release notes][BSP STM32F723E-Discovery-RN] |
| [BSP STM32F7308-Discovery]                  | V1.0.1   | 10-June-2022     | [release notes][BSP STM32F7308-Discovery-RN] |
| [BSP STM32746G-Discovery]                   | V2.0.4   | 10-June-2022     | [release notes][BSP STM32746G-Discovery-RN]  |
| [BSP STM32F7508-Discovery]                  | V1.0.1   | 10-June-2022     | [release notes][BSP STM32F7508-Discovery-RN] |
| [BSP STM32756G_EVAL]                        | V2.1.1   | 10-June-2022     | [release notes][BSP STM32756G_EVAL-RN]       |
| [BSP STM32F769I-Discovery]                  | V2.1.0   | 03-July-2023     | [release notes][BSP STM32F769I-Discovery-RN] |
| [BSP STM32F769I_EVAL]                       | V2.1.1   | 10-June-2022     | [release notes][BSP STM32F769I_EVAL-RN]      |
| [BSP STM32F7xx_Nucleo_144]                  | V1.0.1   | 10-June-2022     | [release notes][BSP STM32F7xx_Nucleo_144-RN] |
| [BSP Adafruit_Shield]<sup>(○)</sup>         | V3.0.3   | 30-April-2018    | [release notes][BSP Adafruit_Shield-RN]      |
| [BSP Common]                                | V4.0.1   | 21-July-2015     | [release notes][BSP Common-RN]               |
| [BSP adv7533]      ([DS][PDF adv7533])      | V1.0.2   | 07-April-2017    | [release notes][BSP adv7533-RN]              |
| [BSP ampire480272] ([DS][PDF ampire480272]) | V1.0.1   | 07-April-2017    | [release notes][BSP ampire480272-RN]         |
| [BSP ampire640480] ([DS][PDF ampire640480]) | V1.0.1   | 07-April-2017    | [release notes][BSP ampire640480-RN]         |
| [BSP dp83848]      ([DS][PDF dp83848])      | V1.0.0   | 12-December-2021 | [release notes][BSP dp83848-RN]              |
| [BSP exc7200]      ([DS][PDF exc7200])      | V1.0.2   | 07-April-2017    | [release notes][BSP exc7200-RN]              |
| [BSP ft3x67]       ([DS][PDF ft3x67])       | V1.0.1   | 03-April-2019    | [release notes][BSP ft3x67-RN]               |
| [BSP ft5336]       ([DS][PDF ft5336])       | V1.0.1   | 07-April-2017    | [release notes][BSP ft5336-RN]               |
| [BSP ft6x06]       ([DS][PDF ft6x06])       | V1.0.2   | 07-April-2017    | [release notes][BSP ft6x06-RN]               |
| [BSP lan8742]      ([DS][PDF lan8742])      | V1.0.1   | 23-November-2019 | [release notes][BSP lan8742-RN]              |
| [BSP mfxstm32l152] ([DS][PDF mfxstm32l152]) | V2.0.1   | 02-June-2017     | [release notes][BSP mfxstm32l152-RN]         |
| [BSP mx25l512]     ([DS][PDF mx25l512])     | V1.0.3   | 02-June-2017     | [release notes][BSP mx25l512-RN]             |
| [BSP n25q128a]     ([DS][PDF n25q128a])     | V1.0.1   | 25-August-2017   | [release notes][BSP n25q128a-RN]             |
| [BSP n25q256a]     ([DS][PDF n25q256a])     | V1.0.1   | 03-April-2019    | [release notes][BSP n25q256a-RN]             |
| [BSP n25q512a]     ([DS][PDF n25q512a])     | V1.0.0   | 28-April-2015    | [release notes][BSP n25q512a-RN]             |
| [BSP nt35510]      ([DS][PDF nt35510])      | V1.0.0   | 11-December-2020 | [release notes][BSP nt35510-RN]              |
| [BSP otm8009a]     ([DS][PDF otm8009a])     | V1.0.5   | 12-February-2021 | [release notes][BSP otm8009a-RN]             |
| [BSP ov5640]       ([DS][PDF ov5640])       | V2.0.0   | 07-February-2020 | [release notes][BSP ov5640-RN]               |
| [BSP ov9655]       ([DS][PDF ov9655])       | V1.0.1   | 07-April-2017    | [release notes][BSP ov9655-RN]               |
| [BSP rk043fn48h]   ([DS][PDF rk043fn48h])   | V1.0.1   | 02-June-2017     | [release notes][BSP rk043fn48h-RN]           |
| [BSP s5k5cag]      ([DS][PDF s5k5cag])      | V1.0.1   | 05-June-2017     | [release notes][BSP s5k5cag-RN]              |
| [BSP st7735]       ([DS][PDF st7735])       | V1.1.2   | 06-June-2017     | [release notes][BSP st7735-RN]               |
| [BSP st7789h2]     ([DS][PDF st7789h2])     | V1.1.2   | 05-June-2017     | [release notes][BSP st7789h2-RN]             |
| [BSP stmpe811]     ([DS][PDF stmpe811])     | V2.0.1   | 05-June-2017     | [release notes][BSP stmpe811-RN]             |
| [BSP ts3510]       ([DS][PDF ts3510])       | V1.0.2   | 05-June-2017     | [release notes][BSP ts3510-RN]               |
| [BSP wm8994]       ([DS][PDF wm8994])       | V2.2.1   | 24-January-2018  | [release notes][BSP wm8994-RN]               |

<sup>(○)</sup> as part of the upstream STM32CubeF7 V1.17.1 Git repository.

[CMSIS]: https://github.com/STMicroelectronics/cmsis_core/tree/v5.4.0_cm7
[CMSIS-RN]: https://arm-software.github.io/CMSIS_5/General/html/cm_revisionHistory.html

[STM32F7xx CMSIS]: https://github.com/STMicroelectronics/cmsis_device_f7/tree/v1.2.8
[STM32F7xx CMSIS-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/cmsis_device_f7/blob/v1.2.8/Release_Notes.html

[STM32F7xx HAL]: https://github.com/STMicroelectronics/stm32f7xx_hal_driver/tree/v1.3.0
[STM32F7xx HAL-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32f7xx_hal_driver/blob/v1.3.0/Release_Notes.html

[BSP STM32F723E-Discovery]: https://github.com/STMicroelectronics/32f723ediscovery-bsp/tree/v1.0.3
[BSP STM32F723E-Discovery-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/32f723ediscovery-bsp/blob/v1.0.3/Release_Notes.html

[BSP STM32F7308-Discovery]: https://github.com/STMicroelectronics/stm32f7308-dk-bsp/tree/v1.0.1
[BSP STM32F7308-Discovery-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32f7308-dk-bsp/blob/v1.0.1/Release_Notes.html

[BSP STM32746G-Discovery]: https://github.com/STMicroelectronics/32f746gdiscovery-bsp/tree/v2.0.4
[BSP STM32746G-Discovery-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/32f746gdiscovery-bsp/blob/v2.0.4/Release_Notes.html

[BSP STM32F7508-Discovery]: https://github.com/STMicroelectronics/stm32f7508-dk-bsp/tree/v1.0.1
[BSP STM32F7508-Discovery-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32f7508-dk-bsp/blob/v1.0.1/Release_Notes.html

[BSP STM32756G_EVAL]: https://github.com/STMicroelectronics/stm32756g-eval-bsp/tree/v2.1.1
[BSP STM32756G_EVAL-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32756g-eval-bsp/blob/v2.1.1/Release_Notes.html

[BSP STM32F769I-Discovery]: https://github.com/STMicroelectronics/32f769idiscovery-bsp/tree/v2.1.0
[BSP STM32F769I-Discovery-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/32f769idiscovery-bsp/blob/v2.1.0/Release_Notes.html

[BSP STM32F769I_EVAL]: https://github.com/STMicroelectronics/stm32f769i-eval-bsp/tree/v2.1.1
[BSP STM32F769I_EVAL-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32f769i-eval-bsp/blob/v2.1.1/Release_Notes.html

[BSP STM32F7xx_Nucleo_144]: https://github.com/STMicroelectronics/stm32f7xx-nucleo-144-bsp/tree/v1.0.1
[BSP STM32F7xx_Nucleo_144-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32f7xx-nucleo-144-bsp/blob/v1.0.1/Release_Notes.html

[BSP Adafruit_Shield]: https://github.com/STMicroelectronics/STM32CubeF7/tree/v1.17.1/Drivers/BSP/Adafruit_Shield
[BSP Adafruit_Shield-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Drivers/BSP/Adafruit_Shield/Release_Notes.html

[BSP Common]: https://github.com/STMicroelectronics/stm32-bsp-common/tree/v4.0.1
[BSP Common-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-bsp-common/blob/v4.0.1/Release_Notes.html

[PDF adv7533]: https://www.analog.com/en/products/adv7533.html
[BSP adv7533]: https://github.com/STMicroelectronics/stm32-adv7533/tree/v1.0.2
[BSP adv7533-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-adv7533/blob/v1.0.2/Release_Notes.html

[PDF ampire480272]: https://docs.rs-online.com/37fb/0900766b8133ac12.pdf
[BSP ampire480272]: https://github.com/STMicroelectronics/stm32-ampire480272/tree/v1.0.1
[BSP ampire480272-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ampire480272/blob/v1.0.1/Release_Notes.html

[PDF ampire640480]: https://docs.rs-online.com/e03d/0900766b812f9e21.pdf
[BSP ampire640480]: https://github.com/STMicroelectronics/stm32-ampire640480/tree/v1.0.1
[BSP ampire640480-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ampire640480/blob/v1.0.1/Release_Notes.html

[PDF dp83848]: https://www.ti.com/product/DP83848-EP
[BSP dp83848]: https://github.com/STMicroelectronics/stm32-dp83848/tree/v1.0.0
[BSP dp83848-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-dp83848/blob/v1.0.0/Release_Notes.html

[PDF exc7200]: https://datasheetspdf.com/datasheet/EXC7200.html
[BSP exc7200]: https://github.com/STMicroelectronics/stm32-exc7200/tree/v1.0.2
[BSP exc7200-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-exc7200/blob/v1.0.2/Release_Notes.html

[PDF ft3x67]: https://www.buydisplay.com/download/ic/FT3267.pdf
[BSP ft3x67]: https://github.com/STMicroelectronics/stm32-ft3x67/tree/v1.0.1
[BSP ft3x67-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ft3x67/blob/v1.0.1/Release_Notes.html

[PDF ft5336]: https://datasheetspdf.com/datasheet/FT5336GQQ.html
[BSP ft5336]: https://github.com/STMicroelectronics/stm32-ft5336/tree/v1.0.1
[BSP ft5336-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ft5336/blob/v1.0.1/Release_Notes.html

[PDF ft6x06]: https://datasheetspdf.com/datasheet/FT6306.html
[BSP ft6x06]: https://github.com/STMicroelectronics/stm32-ft6x06/tree/v1.0.2
[BSP ft6x06-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ft6x06/blob/v1.0.2/Release_Notes.html

[PDF lan8742]: https://datasheetspdf.com/datasheet/LAN8742A.html
[BSP lan8742]: https://github.com/STMicroelectronics/stm32-lan8742/tree/v1.0.1
[BSP lan8742-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-lan8742/blob/v1.0.1/Release_Notes.html

[PDF mfxstm32l152]: https://www.st.com/content/st_com/en/search.html#q=MFXSTM32L152-t=resources-page=1
[BSP mfxstm32l152]: https://github.com/STMicroelectronics/stm32-mfxstm32l152/tree/v2.0.1
[BSP mfxstm32l152-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-mfxstm32l152/blob/v2.0.1/Release_Notes.html

[PDF n25q128a]: https://datasheetspdf.com/datasheet/N25Q128A.html
[BSP n25q128a]: https://github.com/STMicroelectronics/stm32-n25q128a/tree/v1.0.1
[BSP n25q128a-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-n25q128a/blob/v1.0.1/Release_Notes.html

[PDF n25q256a]: https://datasheetspdf.com/datasheet/N25Q256A.html
[BSP n25q256a]: https://github.com/STMicroelectronics/stm32-n25q256a/tree/v1.0.1
[BSP n25q256a-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-n25q256a/blob/v1.0.1/Release_Notes.html

[PDF n25q512a]: https://datasheetspdf.com/datasheet/N25Q512A.html
[BSP n25q512a]: https://github.com/STMicroelectronics/stm32-n25q512a/tree/v1.0.0
[BSP n25q512a-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-n25q512a/blob/v1.0.0/Release_Notes.html

[PDF mx25l512]: https://datasheetspdf.com/datasheet/MX25L512.html
[BSP mx25l512]: https://github.com/STMicroelectronics/stm32-mx25l512/tree/v1.0.3
[BSP mx25l512-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-mx25l512/blob/v1.0.3/Release_Notes.html

[PDF nt35510]: https://datasheetspdf.com/datasheet/NT35510.html
[BSP nt35510]: https://github.com/STMicroelectronics/stm32-nt35510/tree/v1.0.0
[BSP nt35510-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-nt35510/blob/v1.0.0/Release_Notes.html

[PDF otm8009a]: https://datasheetspdf.com/datasheet/OTM8009A.html
[BSP otm8009a]: https://github.com/lipro/stm32-otm8009a/tree/v1.0.5
[BSP otm8009a-RN]: https://htmlpreview.github.io/?https://github.com/lipro/stm32-otm8009a/blob/v1.0.5/Release_Notes.html

[PDF ov5640]: https://www.waveshare.com/w/upload/d/da/OV5640_DataSheet.pdf
[BSP ov5640]: https://github.com/lipro/stm32-ov5640/tree/v2.0.0
[BSP ov5640-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ov5640/blob/v2.0.0/Release_Notes.html

[PDF ov9655]: https://www.waveshare.com/w/upload/0/0a/OV9655.pdf
[BSP ov9655]: https://github.com/lipro/stm32-ov9655/tree/v1.0.1
[BSP ov9655-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ov9655/blob/v1.0.1/Release_Notes.html

[PDF rk043fn48h]: https://mikrocontroller.bplaced.net/wordpress/wp-content/uploads/2018/01/RK043FN48H-CT672B-V1.0.pdf
[BSP rk043fn48h]: https://github.com/STMicroelectronics/stm32-rk043fn48h/tree/v1.0.1
[BSP rk043fn48h-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-rk043fn48h/blob/v1.0.1/Release_Notes.html

[PDF s5k5cag]: https://d1.amobbs.com/bbs_upload782111/files_31/ourdev_570896.pdf
[BSP s5k5cag]: https://github.com/STMicroelectronics/stm32-s5k5cag/tree/v1.0.1
[BSP s5k5cag-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-s5k5cag/blob/v1.0.1/Release_Notes.html

[PDF st7735]: https://datasheetspdf.com/datasheet/ST7735.html
[BSP st7735]: https://github.com/STMicroelectronics/stm32-st7735/tree/v1.1.2
[BSP st7735-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-st7735/blob/v1.1.2/Release_Notes.html

[PDF st7789h2]: https://datasheetspdf.com/datasheet/ST7789H2.html
[BSP st7789h2]: https://github.com/STMicroelectronics/stm32-st7789h2/tree/v1.1.2
[BSP st7789h2-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-st7789h2/blob/v1.1.2/Release_Notes.html

[PDF stmpe811]: https://www.st.com/content/st_com/en/search.html#q=STMPE811-t=resources-page=1
[BSP stmpe811]: https://github.com/STMicroelectronics/stm32-stmpe811/tree/v2.0.1
[BSP stmpe811-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-stmpe811/blob/v2.0.1/Release_Notes.html

[PDF ts3510]: https://datasheetspdf.com/datasheet/TS3510.html
[BSP ts3510]: https://github.com/STMicroelectronics/stm32-ts3510/tree/v1.0.2
[BSP ts3510-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-ts3510/blob/v1.0.2/Release_Notes.html

[PDF wm8994]: https://datasheetspdf.com/datasheet/WM8994.html
[BSP wm8994]: https://github.com/lipro/stm32-wm8994/tree/v2.2.1
[BSP wm8994-RN]: https://htmlpreview.github.io/?https://github.com/lipro/stm32-wm8994/blob/v2.2.1/Release_Notes.html

### Middlewares

| Name                            | Version  | Date             | Release note                                           |
| :---                            | :-----:  | :---             | :-----------                                           |
| [FreeRTOS] ([DS][WEB FreeRTOS]) | V10.2.1  | 17-January-2020  | [release notes][FreeRTOS-RN] ([FreeRTOS][FreeRTOS-UN]) |
| [MbedTLS]  ([DS][WEB MbedTLS])  | V2.16.2  | 25-August-2020   | [release notes][MbedTLS-RN] ([MbedTLS][MbedTLS-UN])    |
| [LwIP]     ([DS][WEB LwIP])     | V2.1.2   | 15-March-2019    | [release notes][LwIP-RN] ([LwIP][LwIP-UN])             |
| [FatFS]    ([DS][WEB FatFS])    | R0.12C   | 18-October-2019  | [release notes][FatFS-RN] ([FatFS][FatFS-UN])          |
| [LibJPEG]  ([DS][WEB LibJPEG])  | V8d      | 29-March-2019    | [release notes][LibJPEG-RN] ([LibJPEG][LibJPEG-UN])    |
| [STM32 USB Device Library]      | V2.11.0  | 25-March-2022    | [release notes][STM32 USB Device Library-RN]           |
| [STM32 USB Host Library]        | V3.4.1   | 04-April-2022    | [release notes][STM32 USB Host Library-RN]             |
| [STM32 Audio PDM]<sup>(●)</sup> | V3.2.0   | 06-November-2019 | [release notes][STM32 Audio PDM-RN]                    |
| [STemWin]<sup>(●)</sup>         | V5.44    | 22-March-2018    | [release notes][STemWin-RN]                            |
| [TouchGFX]<sup>(●)</sup>        | v4.10.0  | 05-November-2018 | [release notes][TouchGFX-RN]                           |

<sup>(●)</sup> as part of the original [STM32CubeFW] download archive, e.g. [STM32CubeF7] V1.17.1.

[WEB FreeRTOS]: https://www.FreeRTOS.org/
[FreeRTOS]: https://github.com/STMicroelectronics/stm32_mw_freertos/tree/v10.2.1
[FreeRTOS-RN]: https://github.com/STMicroelectronics/stm32_mw_freertos/raw/v10.2.1/Source/st_readme.txt
[FreeRTOS-UN]: https://www.FreeRTOS.org/History.txt

[WEB MbedTLS]: https://tls.mbed.org/
[MbedTLS]: https://github.com/lipro/stm32_mw_mbedtls/tree/v2.16.2-20200825
[MbedTLS-RN]: https://github.com/lipro/stm32_mw_mbedtls/raw/v2.16.2-20200825/st_readme.txt
[MbedTLS-UN]: https://github.com/lipro/stm32_mw_mbedtls/raw/v2.16.2-20200825/ChangeLog

[WEB LwIP]: https://savannah.nongnu.org/projects/lwip
[LwIP]: https://github.com/STMicroelectronics/stm32_mw_lwip/tree/v2.1.2
[LwIP-RN]: https://github.com/STMicroelectronics/stm32_mw_lwip/raw/v2.1.2/st_readme.txt
[LwIP-UN]: https://github.com/STMicroelectronics/stm32_mw_lwip/raw/v2.1.2/CHANGELOG

[WEB FatFS]: http://elm-chan.org/fsw/ff
[FatFS]: https://github.com/STMicroelectronics/stm32_mw_fatfs/tree/r0.12c
[FatFS-RN]: https://github.com/STMicroelectronics/stm32_mw_fatfs/raw/r0.12c/src/st_readme.txt
[FatFS-UN]: http://elm-chan.org/fsw/ff/updates.html

[WEB LibJPEG]: https://www.ijg.org/
[LibJPEG]: https://github.com/lipro/stm32_mw_libjpeg/tree/v8d-20190329
[LibJPEG-RN]: https://github.com/lipro/stm32_mw_libjpeg/raw/v8d-20190329/st_readme.txt
[LibJPEG-UN]: https://github.com/lipro/stm32_mw_libjpeg/raw/v8d-20190329/change.log

[STM32 USB Device Library]: https://github.com/STMicroelectronics/stm32_mw_usb_device/tree/v2.11.0
[STM32 USB Device Library-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32_mw_usb_device/blob/v2.11.0/Release_Notes.html

[STM32 USB Host Library]: https://github.com/STMicroelectronics/stm32_mw_usb_host/tree/v3.4.1
[STM32 USB Host Library-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32_mw_usb_host/blob/v3.4.1/Release_Notes.html

[STM32 Audio PDM]: https://www.st.com/STM32CubeFW
[STM32 Audio PDM-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Middlewares/ST/STM32_Audio/Addons/PDM/Release_Notes.html

[STemWin]: https://www.st.com/en/embedded-software/stemwin.html
[STemWin-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Middlewares/ST/STemWin/Release_Notes.html

[TouchGFX]: https://www.st.com/X-CUBE-TOUCHGFX
[TouchGFX-RN]: https://raw.githubusercontent.com/STMicroelectronics/STM32CubeF7/v1.17.1/Middlewares/ST/TouchGFX/changelog.txt

### Utilities

| Name                       | Version  | Date             | Release note                                 |
| :---                       | :-----:  | :---             | :-----------                                 |
| [CPU]<sup>(○)</sup>        | V1.1.0   | 20-November-2014 | [release notes][CPU-RN]                      |
| [Fonts]<sup>(○)</sup>      | V1.0.0   | 18-February-2014 | [release notes][Fonts-RN]                    |
| [JPEG]<sup>(○)</sup>       | V2.0.0   | 03-June-2016     | [release notes][JPEG-RN]                     |
| [Log]<sup>(○)</sup>        | V1.0.1   | 18-November-2016 | [release notes][Log-RN]                      |

<sup>(○)</sup> as part of the upstream [STM32CubeFW] Git repository, e.g.
[STM32CubeF7](https://github.com/STMicroelectronics/STM32CubeF7)
[V1.17.1](https://github.com/STMicroelectronics/STM32CubeF7/tree/v1.17.1).

[CPU]: https://github.com/STMicroelectronics/STM32CubeF7/tree/v1.17.1/Utilities/CPU
[CPU-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Utilities/CPU/Release_Notes.html

[Fonts]: https://github.com/STMicroelectronics/STM32CubeF7/tree/v1.17.1/Utilities/Fonts
[Fonts-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Utilities/Fonts/Release_Notes.html

[JPEG]: https://github.com/STMicroelectronics/STM32CubeF7/tree/v1.17.1/Utilities/JPEG
[JPEG-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Utilities/JPEG/Release_Notes.html

[Log]: https://github.com/STMicroelectronics/STM32CubeF7/tree/v1.17.1/Utilities/Log
[Log-RN]: https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeF7/blob/v1.17.1/Utilities/Log/Release_Notes.html

</div>
