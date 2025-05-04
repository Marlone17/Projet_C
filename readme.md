## Database 

Ce programme permet de :

-  **Stocker des utilisateurs** dans un **arbre binaire de recherche** (trié par ID),
-  **Afficher** les utilisateurs dans l'**ordre croissant** selon leur ID,
-  **Rechercher**,  **modifier** et  **supprimer** un utilisateur,
-  **Enregistrer** les données dans un fichier **CSV** pour la persistance.

## Fonctionnement général

Le fichier `main()` exécute les étapes suivantes :

-  Initialise un **arbre binaire vide**,
-  Crée et **insère trois utilisateurs** dans l’arbre,
-  **Affiche** les utilisateurs présents,
-  **Enregistre** les données dans un fichier **CSV** (`usersTable.csv`),
-  **Recherche** un utilisateur par son **ID**,
-  **Modifie** les informations d’un utilisateur existant,
-  **Supprime** un utilisateur de l’arbre,
-  **Réaffiche** l’arbre mis à jour.

###  Commandes à exécuter dans le terminal :

```bash
gcc database.c && ./a.out
```

## SERVER Communication Client-Serveur en C

## Description
Ce programme implémente un système de communication entre un serveur et un client en utilisant des **sockets**. Le serveur stocke des utilisateurs dans un arbre binaire et répond aux requêtes des clients pour rechercher des utilisateurs par leur ID.

## Serveur - `server.c`

Le serveur est chargé de :
1. Accepter les connexions des clients.
2. Recevoir des requêtes contenant des IDs utilisateurs.
3. Rechercher les utilisateurs dans un arbre binaire.
4. Envoyer les informations de l'utilisateur ou un message d'erreur au client.

### Fonctionnalités :

- **Création d'un socket serveur** pour accepter les connexions.
- **Recherche dans l'arbre binaire** des utilisateurs.
- **Envoi des résultats** au client (si l'utilisateur est trouvé).


## Client - client.c

Le client est chargé de :

1. Se connecter au serveur.

2. Envoyer une requête contenant un ID utilisateur.

3. Afficher la réponse du serveur (si l'utilisateur est trouvé ou non).

4. Fonctionnalités :

    Création du socket client pour se connecter au serveur.

    Envoi de la requête au serveur (ID utilisateur).

    Réception et affichage de la réponse du serveur.

###  Commandes à exécuter dans le terminal :

```bash
gcc server.c database2.c -o server && gcc client.c -o client

```
Une fois que c'est fait , cela génère deux ficher **server** et **client** => Puis ouvrir deux onglet deux terminal différents et lancer en premier le server : `
```bash
./server
```
Puis lancer le client :
```bash
./client
```

Après avoir lancé le client , entré un ID qui est déja présent dans le csv pour exectuer des actions 


## MALWARE


## Étape 1 : Compiler la bibliothèque partagée

Pour compiler le code source en une bibliothèque partagée (shared library), utilisez la commande suivante :

```bash
gcc -shared -fPIC -o first_hook_test.so first_hook_test.c -ldl
```

## Etape 2 :Exécuter le programme avec la bibliothèque partagée
    Une fois la bibliothèque partagée compilée, vous pouvez l'utiliser pour intercepter les appels à la fonction open en définissant la variable d'environnement LD_PRELOAD avant d'exécuter un programme. Par exemple, pour intercepter l'accès au fichier /etc/passwd avec la commande cat, utilisez :

```bash
LD_PRELOAD=./first_hook_test.so cat /etc/passwd
```

## LD_PRELOAD=./first_hook_test.so ## :
 Cette variable d'environnement indique au système de charger la bibliothèque partagée first_hook_test.so avant toutes les autres bibliothèques, ce qui permet de redéfinir la fonction open pendant l'exécution du programme.

## cat /etc/passwd ## :
    Exécute la commande cat pour afficher le contenu du fichier /etc/passwd. Grâce à LD_PRELOAD, la fonction open est interceptée et bloquée pour ce fichier spécifique.