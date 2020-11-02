# Instructions

There are two (2) methods of installing Ubuntu on your system: using VirtualBox or Windows Subsystem for Linux. You may
use either method, as long as you get Ubuntu installed.

VirtualBox is the tried and true method, and can be used on most systems. However, it may be slower, and getting data
into and out of Ubuntu may be a bit tricky.

The Windows Subsystem for Linux method is faster, but requires an up-to-date Windows 10 system. However, this allows you
to get at files directly, and even use your Windows editor to do work.

## VirtualBox Method

Use the following instructions to install VirtualBox, and then Ubuntu

Alternatively, use the following instructions:
https://fossbytes.com/how-to-install-ubuntu-20-04-lts-virtualbox-windows-mac-linux/

### Setting up your system for VirtualBox

1. Reboot your computer and enter the BIOS menu 
2. Navigate to the menu Security and then Virtualization. You need to enable Virtualization! Then save changes and reboot.

### Download VirtualBox

Download and Install "VirtualBox 6.1": https://www.virtualbox.org/

### Download Ubuntu

1. Head to Ubuntu website (https://ubuntu.com)
2. Go to the "Download" tab
3. Select Ubuntu Desktop
4. Download Ubuntu 20.04.1 LTS

### Install Ubuntu

Type: Linux
Version: Ubuntu (64-bit)

Mem:  4G = (4096MB)  (Look in the box)

Accept the defaults:

- Create a virtual disk now
- VDI 
- Dynamically allocated
- Disk Size: 30 - 40 G  (Look in the box)

Now start the VM, pick the Ubuntu image, and Install

Normal Install, Download updates AND also third party software.

Have a coffee while installing

After Install, change the following settings:

Device-> Shared Clipboard: Bidirectional
Device-> Drag and Drop: Bidirectional
Device-> Insert Guest edition CD

Power off. Then go to Settings -> Display -> Enable 3D Acceleration

## Windows Subsystem for Linux

Instructions can be found here:

https://docs.microsoft.com/en-us/windows/wsl/install-win10

It is also recommended that you install Windows Terminal from the Microsoft Store.

## Update Ubuntu and install packages

Once Ubuntu is installed, either through VirtualBox or WSL, start Terminal and run the following commands:

sudo apt update
sudo apt upgrade
sudo apt dist-upgrade

### Install C Tools

Afterwards, install the C compiler and other tools:

sudo apt install build-essential

