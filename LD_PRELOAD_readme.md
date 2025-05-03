Premiermement il faut compiler le code en une bliblio partageé donc =>  gcc -shared -fPIC -o first_hook_test.so first_hook_test.c -ldl
Deuxiement on execute le programme : LD_PRELOAD=./first_hook_test.so cat /etc/passwd
Voir pour le mettre dans .bashrc avec Mawlone