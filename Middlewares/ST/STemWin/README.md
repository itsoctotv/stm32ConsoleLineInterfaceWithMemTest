# This middleware library is unavailable to the public

This is **STemWin**: *A Professional graphical stack library enabling the
building up of Graphical User Interfaces (GUIs) ([AN4323])*. This middleware
library **along with** the projects (demos, applications, and examples) using
it, are **not available** without accepting the special *STMicroelectronics
Software License Agreement for STemWin* ([SLA0048]).

Please refer also to the [Release_Notes.md] file at the root of this repository
for further details.

[SLA0048]: https://www.st.com/resource/en/license/SLA0048_STemWin.pdf
[Release_Notes.md]: ../../../Release_Notes.md#some-middleware-libraries-are-unavailable-along-with-this-repository
[AN4323]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/DM00089670.pdf

## About this middleware library

**STemWin** ([here a description and an older release][STemWin] V5.32-20160205)
was the version of **emWin** by *SEGGER* provided by *STMicroelectronics* with
a free licence until the purchase of *DRAUPNER* in 2018 (the developer and
supplier of TouchGFX, see below). The licence for free use refers exclusively
to these versions, an upgrade using SEGGER's emWin is neither possible nor
permitted.

You can still use the last version of STemWin (v5.x) for free and you will still
find them in the current [STM32CubeFW] package, but since STMicroelectronics has
purchase *DRAUPNER* in 2018 it has been developing its own and now much more
powerful graphics solution called [TouchGFX].

[STemWin]: https://www.st.com/STemWin
[TouchGFX]: https://www.st.com/TouchGFX
[STM32CubeFW]: https://www.st.com/STM32CubeFW

## Applicable STM32CubeFW packages

The **STemWin** middleware library is applicable on following architectures:

* **V5.32 (27-April-2017)**: ARM Cortex-M0: [STM32CubeF0]
* **V5.44 (22-March-2018)**: ARM Cortex-M3: [STM32CubeF1], [STM32CubeF2], [STM32CubeL1]
* **V5.44 (22-March-2018)**: ARM Cortex-M4: [STM32CubeF3], [STM32CubeF4], [STM32CubeL4]
* **V5.44 (22-March-2018)**: ARM Cortex-M7: [STM32CubeF7], [STM32CubeH7]

[STM32CubeF0]: https://www.st.com/STM32CubeF0
[STM32CubeF1]: https://www.st.com/STM32CubeF1
[STM32CubeF2]: https://www.st.com/STM32CubeF2
[STM32CubeF3]: https://www.st.com/STM32CubeF3
[STM32CubeF4]: https://www.st.com/STM32CubeF4
[STM32CubeF7]: https://www.st.com/STM32CubeF7
[STM32CubeH7]: https://www.st.com/STM32CubeH7
[STM32CubeL1]: https://www.st.com/STM32CubeL1
[STM32CubeL4]: https://www.st.com/STM32CubeL4

### STemWin to STM32CubeFW relation

|       |  [STM32CubeF0]  |  [STM32CubeF1]  |  [STM32CubeF2]  |  [STM32CubeF3]  |  [STM32CubeF4]  |  [STM32CubeF7]  |  [STM32CubeH7]  |  [STM32CubeL1]  |  [STM32CubeL4]  |
|:-----:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|
|V1.28.x|                 |                 |                 |                 |   <br/>–––––    |                 |                 |                 |                 |
|V1.27.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.26.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.25.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.24.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.23.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.22.x|                 |                 |                 |                 |V5.44<br/>180322 |                 |                 |                 |                 |
|V1.21.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.20.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |                 |
|V1.19.x|                 |                 |                 |                 |     :<br/>:     |                 |                 |                 |   <br/>–––––    |
|V1.18.x|                 |                 |                 |                 |     :<br/>:     |   <br/>–––––    |                 |                 |     :<br/>:     |
|V1.17.x|                 |                 |                 |                 |V5.40<br/>170620 |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.16.x|                 |                 |                 |                 |     :<br/>:     |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.15.x|                 |                 |                 |                 |V5.32<br/>161115 |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.14.x|                 |                 |                 |                 |     :<br/>:     |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.13.x|                 |                 |                 |                 |V5.32<br/>160205 |V5.44<br/>180322 |                 |                 |V5.44<br/>180322 |
|V1.12.x|   <br/>–––––    |                 |                 |   <br/>–––––    |     :<br/>:     |     :<br/>:     |   <br/>–––––    |                 |     :<br/>:     |
|V1.11.x|     :<br/>:     |                 |                 |V5.44<br/>180322 |     :<br/>:     |     :<br/>:     |     :<br/>:     |   <br/>–––––    |     :<br/>:     |
|V1.10.x|     :<br/>:     |                 |   <br/>–––––    |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |
|V1.9.x |     :<br/>:     |   <br/>–––––    |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |V5.44<br/>180322 |V5.40<br/>170620 |
|V1.8.x |     :<br/>:     |V5.44<br/>180322 |V5.44<br/>180322 |     :<br/>:     |V5.28<br/>150626 |V5.40<br/>170620 |     :<br/>:     |     :<br/>:     |     :<br/>:     |
|V1.7.x |V5.32<br/>160205 |     :<br/>:     |     :<br/>:     |V5.32<br/>160205 |     :<br/>:     |     :<br/>:     |     :<br/>:     |V5.32<br/>160205 |     :<br/>:     |
|V1.6.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |V5.32<br/>161115 |     :<br/>:     |     :<br/>:     |V5.32<br/>160205 |
|V1.5.x |V5.28<br/>150626 |V5.32<br/>161115 |V5.32<br/>161115 |     :<br/>:     |V5.26<br/>150306 |V5.32<br/>160205 |     :<br/>:     |     :<br/>:     |     :<br/>:     |
|V1.4.x |     :<br/>:     |     :<br/>:     |V5.32<br/>160205 |V5.28<br/>150626 |V5.26<br/>141225 |     :<br/>:     |V5.44<br/>180322 |V5.28<br/>150626 |     :<br/>:     |
|V1.3.x |V5.28<br/>150415 |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |
|V1.2.x |V5.26<br/>141020 |V5.28<br/>150626 |V5.28<br/>150626 |     :<br/>:     |V5.24b<br/>140613|     :<br/>:     |     :<br/>:     |V5.26<br/>150306 |     :<br/>:     |
|V1.1.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |     :<br/>:     |V5.22<br/>140225 |V5.28<br/>150626 |V5.40<br/>170620 |     :<br/>:     |V5.28<br/>150626 |
|V1.0.x |V5.24b<br/>140613|V5.26<br/>141208 |V5.22<br/>140225 |V5.24b<br/>140613|V5.22<br/>131115 |V5.28<br/>150415 |V5.32<br/>170427 |V5.24b<br/>140613|V5.28<br/>150415 |
