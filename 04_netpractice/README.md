## Description
The goal of this project is to understand the basics of computer networking, such as configuring IP addresses, connecting devices through a router and subnetting.

## Instructions

1. Download the folder
2. Navigate to `index.html`  double click to open the web page
3. Choose the tab - training or evaluation.
   For training, key in the ID.
   For evaluation, leave it blank.
4. For training, upon entering, check out the goals at the top of the page. 
    a. At the start of every new question, it is all listed KO. The goal is to route the packets correctly by filling in the correct subnet mask and IP address. Once done, check if the answers are correct, click on `Check`. If the packets are routed correctly, the goals will change to OK. Else, it will remain as KO.
    b. The data logs are on the right side of the page, which may help to identify what has gone wrong with the routing.
    c. If the packets are routed correctly and all goals changed to OK, click on `Get my config` to save a `.json` file. That will serve as a check for the system to verify the answers. Else, click on `next` to move on to the next question.
5. For evaluation, evaluatees have 15 minutes to answer 3 questions randomly chosen from level 5 to 10. Simply answer the question and click submit.


## Resources

### TCP/IP addressing

TCP/IP refers to the Transmission Control Protocol / Internet Protocol, which is a communication model used by networks and the Internet to manage how data moves across the web.

IP stands for Internet Protocol which is a unique number that identifies devices on a network. Each device, as long as it is connected to the Internet (eg printer, laptop, smart door, cctv etc), has an IP address which is required to send and receive data. It also allows networks to correctly identify source and destination devices, ensuring that data packets are delivered to its intended recipient.
IP addresses are divided into 2 categories - public and private. Private IP addresses are reserved for internal networking such as homes, offices and are not routable on the public internet. The private IP addresses range from 10.0.0.0/8 (10.0.0.0 - 10.255.255.255), 172.16.0.0/12 (172.16.0.0 - 172.31.255.255) and 192.168.0.0/16 (192.168.0.0 - 192.168.255.255). The rest are public IP address (1.0.0.0 - 233.255.255.255 excluding private IP addresses). These are addresses that can be routed to the Internet. 

127.0.0.0 is the loopback that a computer uses to send network traffic to itself, which is also known as local host. It is essential for testing networking software, troubleshooting and running local services.

TCP ensures that data is broken into packets, delivered in the right order and arrives without errors.

Together, they enable devices to communicate with one another by sending and receiving data packets across networks.

### Subnets / Masks

A subnet is a network inside a network. It is a large group of network divided into smaller groups of network and in each subnet contains a group of devices. Subnetting improves network performance, organisation and security by grouping devices into separate network segments, isolating each network from one another.

Each network of subnet 255.255.255.0 can only take a maximum of 254 devices starting from XXX.XXX.XXX.0-255, with `.0` being the first default gateway and `.255` being the broadcast IP. If all 254 IPs have been used, the 255th device (or any beyond) will be unable to get a valid IP from the DHCP, causing connection issues. In that case, we will need to change the mask to `/23 (255.255.254.0)` , creating a larger subnet with 510 usable IPs, effectively merging two `/24` subnets into one.

| Subnet Mask | No of IP  | Usable IP | CIDR 
|:-------:|:-----:|:------:|:------:|
| 255.255.255.0 | 255 | 254 | /24 |
| 255.255.255.128 | 128 | 126 | /25 |
| 255.255.255.192 | 64 | 62 | /26 |
| 255.255.255.224 | 32 | 30 | /27 |
| 255.255.255.240 | 16 | 14 | /28 |
| 255.255.255.248 | 8 | 6 | /29 |
| 255.255.255.252 | 4 | 2 | /30 |
| 255.255.255.254 | 2 | 0 | /31 |
| 255.255.255.255 | 1 | 1 | /32 |

It is also possible and common to take a single block of IP addresses (e.g. 192.168.14/24) and carve it into several smaller independent subnets using different CIDR masks. These devices are usually physically connected to the same router so they can "talk" to each other.

Scenario 1: Two /26 Subnets<br>
Host A: 192.168.14.2/26 belongs to the first subnet range: .0 to .63 <br>
Host B: 192.168.14.140/26 belongs to the third subnet range: .128 to .191 <br>
Result: These two hosts are on separate subnets. To talk to each other, they must go through a router. <br>
<br>
Scenario 2: Mixed Masks (/26 and /28)<br>
Host A: 192.168.14.2/26 (Range: .0 – .63)<br>
Host B: 192.168.14.140/28 (Range: .128 – .143)<br>
Host C: 192.168.14.240/28 (Range: .240 – .255)<br>
Host D: 192.168.14.156/28 (Range: .144 – .159)<br>
Result: This is perfectly valid as long as the ranges do not "overlap."<br>

Key Rules to remember:
- No overlap: Subnet A cannot "bleed" into Subnet B's range. If Subnet A ends at `.63`, subnet B must start at `.64` or higher. Each host also needs a gateway address that exists inside its own subnet range.

### Default Gateway

Default Gateway is the network device, usually a router that forwards traffic from a local network to external networks when no specific route exists. Each device on a network sends traffic destined for other networks through the default gateway.

The default gateway is identified by its IP address and is commonly configured as the first usable IP address in a subnet (eg xxx.xxx.xxx.1).

### Router
A router is a networking device that acts as a central hub, connecting your home or office network (LAN) to the internet (WAN). It's main function is to connect multiple networks together by using a routing table.

### Switch
A switch connect multiple devices within a single network (LAN) to share resources like printer or allow computers to talk to one another

### OSI Model

The Open Systems Interconnection (OSI) Model is a conceptual framework that standardises how data is transmitted across a network. It consists of 7 layers, each responsible for a specific function in the communication process.

The 7 layers are:

Application Layer - Interface the user interacts with (HTTP, FTP, Email)

Presentation Layer - Data translation, encryption, compression (Jpeg, mp4)

Session Layer - Managing “conversation” between applications

Transport Layer - End to end connections (TCP, UDP)

Network Layer - Paths (IP addresses, routers, ARP)

Data Link Layer - Physical addressing (MAC addresses)

Physical layer - Hardware (cables, wires, switches)

### Network Hops

Internet hops are the individual intermediate steps or segments that a data packets passes through as they travel from a source to a destination across networks. Each time the packet is forwarded from one network segment to another, it counts as one hop. Generally, a higher number of hops indicates a longer or more complex route, which may increase latency.

### AI Usage

AI is mainly used in the basic understanding of subnet masks and hops. It is also used in paraphrasing of this README sections.
