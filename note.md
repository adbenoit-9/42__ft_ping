## ICMP
*Internet Control Message Protocol*

### Header
*32 bits*

- Type (8 bits): type de notif du pquet ICMP
- Code (8 bits): status de la reponse a la requete precedente
- checksum: 

https://www.geeksforgeeks.org/ping-in-c/
  switch(param_1) {
  case 0:
    pcVar4 = "Echo Reply\n";
    break;
  default:
    uVar2 = dcgettext(0,"Bad ICMP type: %d\n",5);
    __printf_chk(1,uVar2,param_1);
    goto LAB_00106880;
  case 3:
    switch(param_2) {
    case 0:
      pcVar4 = "Destination Net Unreachable\n";
      break;
    case 1:
      pcVar4 = "Destination Host Unreachable\n";
      break;
    case 2:
      pcVar4 = "Destination Protocol Unreachable\n";
      break;
    case 3:
      pcVar4 = "Destination Port Unreachable\n";
      break;
    case 4:
      uVar2 = dcgettext(0,"Frag needed and DF set (mtu = %u)\n",5);
      __printf_chk(1,uVar2,param_3);
      goto joined_r0x001069a5;
    case 5:
      pcVar4 = "Source Route Failed\n";
      break;
    case 6:
      pcVar4 = "Destination Net Unknown\n";
      break;
    case 7:
      pcVar4 = "Destination Host Unknown\n";
      break;
    case 8:
      pcVar4 = "Source Host Isolated\n";
      break;
    case 9:
      pcVar4 = "Destination Net Prohibited\n";
      break;
    case 10:
      pcVar4 = "Destination Host Prohibited\n";
      break;
    case 0xb:
      pcVar4 = "Destination Net Unreachable for Type of Service\n";
      break;
    case 0xc:
      pcVar4 = "Destination Host Unreachable for Type of Service\n";
      break;
    case 0xd:
      pcVar4 = "Packet filtered\n";
      break;
    case 0xe:
      pcVar4 = "Precedence Violation\n";
      break;
    case 0xf:
      pcVar4 = "Precedence Cutoff\n";
      break;
    default:
      pcVar4 = "Dest Unreachable, Bad Code: %d\n";