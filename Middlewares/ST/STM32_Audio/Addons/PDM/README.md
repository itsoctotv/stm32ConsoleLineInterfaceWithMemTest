# This middleware library is unavailable to the public

The **PDM2PCM library** has the function to **decimate and filter out a
Pulse Density Modulated (PDM)** stream from a digital microphone, in order
to **convert it to a Pulse Code Modulated (PCM)** signal output stream.

The **PCM output** stream is implemented at a *sampling rate of 16 kHz* with
a *16-bits resolution*. Various decimation factors can be configured, in order
to *adapt to various PDM clocks*. Digital microphone *gain is configurable*
at any time and *allows 1dB step* in the range of *-12dB to +51dB*.
A *configurable high-pass filter* and a *digital volume* are also proposed.

The **PDM input** takes a PDM signal (*768 kHz to 2.048 MHz*) stream of
*1-bit digital samples*. This signal is *acquired in blocks of 8 samples*
by using a synchronous serial port (**SPI** or **I2S**) of the STM32
microcontroller ([UM2372]).

This middleware library **along with** the projects (demos, applications, and
examples) using it, are **not available** without accepting the special
*STMicroelectronics Software License Agreement for STM32CubeFW* ([SLA0048]).

Please refer also to the [Release_Notes.md] file at the root of this repository
for further details.

[SLA0048]: https://www.st.com/resource/en/license/SLA0048_STM32CubeFW.pdf
[Release_Notes.md]: ../../../../../Release_Notes.md#some-middleware-libraries-are-unavailable-along-with-this-repository
[UM2372]: https://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00482421.pdf

## About this middleware library

The **PDM2PCM** library ([here a description and an older release][AudioPDM-MW]
v3.2.0-20191106) is a closed-source code project for unknown reasons, and there
is more speculation than exact knowledge about the specific implementation of
modern digital filtering technology. One suspects IIR filter, see:
*[Open source PDM filter for MP45DT02 mic]*.

[AudioPDM-MW]: https://www.st.com/AudioPDM-MW
[Open source PDM filter for MP45DT02 mic]: https://community.st.com/t5/stm32-mcus-other-solutions/open-source-pdm-filter-for-mp45dt02-mic/m-p/504363/highlight/true#M3015

Mainly the PDM2PCM library was **developed and optimized for the STM32F4/F7/H7**
series. But there are also reports about using on [STM32G4/L4] or [STM32WL].
The firmware packages for STM32F2/H5/WB also contain the PDM2PCM library.
That means that at least a STM32 microcontroller based on [Cortex-M4/M7] with
a on-chip CRC unit is required, FPU should be mandatory. A Cortex-M3 or
Cortex-M33 also seems to be usable with latest library releases. See also
[Study OF PDM to PCM conversion].

[STM32G4/L4]: https://community.st.com/t5/stm32cubemx-mcus/why-is-pdm2pcm-not-enabled-for-stm32g4-in-cubemx/m-p/85020/highlight/true#M1844
[STM32WL]: https://community.st.com/t5/mems-sensors/dm2pcm-library-for-stm32wl-microcontrollers-missing/m-p/138295/highlight/true#M2921
[Cortex-M4/M7]: https://community.st.com/t5/stm32cubemx-mcus/is-pdm2pcm-software-library-available-to-cortex-m0-if-it-s/m-p/193672/highlight/true#M8706
[Study OF PDM to PCM conversion]: https://github.com/VictorTagayun/STM32_PDM2PCM_PDM-Stream_to_PCM-Processing

**Alternatives and papers:**

- [PDM bitstream FIR filter] by Oleg Volkov (2013)
- [Pulse Density Modulation for software DACs] by Daniel Beer (2011)
- [Design of a Multi-Stage PDM to PCM Decimation Pipeline] by Tom Verbeure (2020)
- [PDM microphone experiments] by Tom Verbeure (2020)

[PDM bitstream FIR filter]: https://github.com/olegv142/pdm_fir
[Pulse Density Modulation for software DACs]: https://dlbeer.co.nz/articles/pdm.html
[Design of a Multi-Stage PDM to PCM Decimation Pipeline]: https://tomverbeure.github.io/2020/12/20/Design-of-a-Multi-Stage-PDM-to-PCM-Decimation-Pipeline.html
[PDM microphone experiments]: https://github.com/tomverbeure/pdm

## Applicable STM32CubeFW packages

The **PDM2PCM** middleware library is applicable on following architectures:

* **V3.2.0 (06-November-2019)**: ARM Cortex-M3: [STM32CubeF2]
* **V3.3.0 (20-April-2020)**: ARM Cortex-M4: [STM32CubeF4], [STM32CubeWB]
* **V3.3.0 (20-April-2020)**: ARM Cortex-M7: [STM32CubeF7], [STM32CubeH7]
* **V3.4.0 (02-February-2021)**: ARM Cortex-M33: [STM32CubeH5]

[STM32CubeF2]: https://www.st.com/STM32CubeF2
[STM32CubeF4]: https://www.st.com/STM32CubeF4
[STM32CubeF7]: https://www.st.com/STM32CubeF7
[STM32CubeH5]: https://www.st.com/STM32CubeH5
[STM32CubeH7]: https://www.st.com/STM32CubeH7
[STM32CubeWB]: https://www.st.com/STM32CubeWB

### PDM2PCM to STM32CubeFW relation

|       |  [STM32CubeF2]  |  [STM32CubeF4]  |  [STM32CubeF7]  |  [STM32CubeH5]  |  [STM32CubeH7]  |  [STM32CubeWB]  |
|:-----:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|
|V1.28.x|                 |   <br/>–––––    |                 |                 |                 |                 |
|V1.27.x|                 |     :<br/>:     |                 |                 |                 |                 |
|V1.26.x|                 |V3.3.0<br/>200420|                 |                 |                 |                 |
|V1.25.x|                 |V3.2.0<br/>191106|                 |                 |                 |                 |
|V1.24.x|                 |     :<br/>:     |                 |                 |                 |                 |
|V1.23.x|                 |V3.1.0<br/>180929|                 |                 |                 |                 |
|V1.22.x|                 |     :<br/>:     |                 |                 |                 |                 |
|V1.21.x|                 |     :<br/>:     |                 |                 |                 |                 |
|V1.20.x|                 |     :<br/>:     |                 |                 |                 |                 |
|V1.19.x|                 |     :<br/>:     |                 |                 |                 |                 |
|V1.18.x|                 |V3.0.0<br/>170228|   <br/>–––––    |                 |                 |   <br/>–––––    |
|V1.17.x|                 |     :<br/>:     |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.16.x|                 |     :<br/>:     |V3.2.0<br/>191106|                 |                 |     :<br/>:     |
|V1.15.x|                 |     :<br/>:     |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.14.x|                 |     :<br/>:     |V3.1.0<br/>180929|                 |                 |     :<br/>:     |
|V1.13.x|                 |     :<br/>:     |     :<br/>:     |                 |                 |     :<br/>:     |
|V1.12.x|                 |     :<br/>:     |     :<br/>:     |                 |   <br/>–––––    |     :<br/>:     |
|V1.11.x|                 |     :<br/>:     |     :<br/>:     |                 |     :<br/>:     |     :<br/>:     |
|V1.10.x|   <br/>–––––    |     :<br/>:     |     :<br/>:     |                 |     :<br/>:     |V3.3.0<br/>200420|
|V1.9.x |V3.2.0<br/>191106|     :<br/>:     |V3.0.1<br/>171229|                 |     :<br/>:     |                 |
|V1.8.x |V3.1.0<br/>180929|V2.1.0<br/>150331|     :<br/>:     |                 |V3.3.0<br/>200420|                 |
|V1.7.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |                 |     :<br/>:     |                 |
|V1.6.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |                 |     :<br/>:     |                 |
|V1.5.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |                 |     :<br/>:     |                 |
|V1.4.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |                 |V3.1.0<br/>180929|                 |
|V1.3.x |     :<br/>:     |     :<br/>:     |     :<br/>:     |                 |     :<br/>:     |                 |
|V1.2.x |V2.1.0<br/>150331|     :<br/>:     |     :<br/>:     |   <br/>–––––    |V3.0.0<br/>170228|                 |
|V1.1.x |V2.0.1<br/>131217|     :<br/>:     |     :<br/>:     |     :<br/>:     |                 |                 |
|V1.0.x |                 |V2.0.1<br/>131217|V2.1.0<br/>150331|V3.4.0<br/>210202|                 |                 |
|F4DISCO|                 |V1.1.0<br/>111028|                 |                 |                 |                 |
