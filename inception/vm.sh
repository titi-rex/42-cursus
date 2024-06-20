#!/bin/bash

apt update -y && apt upgrade -y
apt install -y sudo ssh curl docker git make

bash -c "$(curl -fsSL https://raw.githubusercontent.com/ohmybash/oh-my-bash/master/tools/install.sh)"

ssh-keygen -f ~/.ssh/id_rsa -N ''


