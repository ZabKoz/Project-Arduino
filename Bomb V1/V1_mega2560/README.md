

<h1 align="center">
   Arduino bomb replica version 1
</h1>

## Connecting components
```cmd
  \\\\\\\\\\\\\\\\\\\\\\\\\\\
  pin 53 -> Red diode
  pin 51 -> Yellow diode
  pin 49 -> Green diode
  \\\\\\\\\\\\\\\\\\\\\\\\\\\
  LCD [D7] -> Arduino [A9]
  LCD [D6] -> Arduino [A10]
  LCD [D5] -> Arduino [A11]
  LCD [D4] -> Arduino [A12]
  LCD [E] -> Arduino [A13]
  LCD [RW] -> Arduino [GND]
  LCD [RS] -> Arduino [A14]
  LCD [V0] -> Arduino [Potenciometer 10K [CENTER]]
  LCD [VDD] -> Arduino [Potenciometer 10K [5V - RIGHT]]
  LCD [DVSS] -> Arduino [Potenciometer 10K [GND - LEFT]]
  \\\\\\\\\\\\\\\\\\\\\\\\\\\
  Speaker [+] -> Arduino [52]
  Speaker [-] -> Arduino [GND]
```