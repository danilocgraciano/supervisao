# supervisao

Os arquivos deste repositório demonstram a viabilidade de troca de mensagens entre as placas NodeMCU, Arduino Mega com equipamentos que se comunicam
através do protocolo Modbus.

Utilizando Arduino Mega, tanto TTL quanto RS485 se mostraram viáveis, já com a placa NodeMCU só foi possível utilizando RS485.

A comunicaço TTL foi feita através do jampeamento dos pinos 1,4 e 5 do CI 7576BP presente no equipamento.

Foi utilizado um conversor TTL -> RS485 visto que ambas as placas possuem apenas TTL, a placa Arduino funciona a 5v já a placa NodeMCU 3.3v, o que pode
ser a razão do não funcionamento TTL.
