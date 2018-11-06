# turing machine

### een grafisch voortelling van een turringmachine gebruikmakend van QT.

## functionaliteit
* xml file die een turing machine voorsteld inladen
* stap voor stap turing machine laten uitvoeren
* multi tape naar single tape omzetten


## opbouw xml file
```
<TM>

  <InputAlphabet>
    <symbol>"symbol1"</symbol>
    <symbol>"symbol2"</symbol>
  </InputAlphabet>
  
  <TapeAlphabet>
    <symbol>"symbol1"</symbol>
    <symbol>"symbol2"</symbol>
  </TapeAlphabet>
  
  <Blank>"bankcharacter</Blank>
  
  <States>
    <state>"state1"</state>
    <state>"state2"</state>
    <state>"state3"</state>
  </States>
  
  <Transitions>
    <transition>
      <from>"state1"</from>
      <to>"state2"</to>
      <read>"tapesymbol1"</read>
      <write>"tapesymbol2"</write>
      <dir>"R | L"</dir>
    </transition>
  </Transitions>
  
  <Startstate>
    <name>"state"</name>
  </Startstate>
  
  <AcceptingStates>
    <state>
      <name>"state"</name>
    </state>
  </AcceptingStates>
  
</TM>
```
