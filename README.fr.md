<p align="center"><img src="https://github.com/Trixciel/Xi_Assets/blob/main/Xi.png" /></p>

<p align="center">
  <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="cc by-nc-sa 4.0" src="https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-525252.svg?labelColor=292929&logo=creative%20commons&style=for-the-badge" /></a>
  <br/>
</p>

> Don't understand french ? speak english ? here's the [english README](./README.md) !

## À propos

Xi est un fork de Upsilon, mais il est plus développé comme un projet détente plutôt que comme un OS.

## Installation

### Manuelle

*A l'heure actuelle, seule l'installation manuelle est possible.*

Tout d'abord, suivez **la première étape** [ici](https://www.numworks.com/resources/engineering/software/build/), puis :

<details>
  <summary><b>Modèle n0100</b></summary>

(note : vous pouvez changer `EPSILON_I18N=fr` en `en`, `nl`, `pt`, `it`, `de`, `es` ou `hu`).

```bash
git clone --recursive https://github.com/Trixciel/Xi.git
cd Xi
git checkout omega-master
make MODEL=n0100 clean
make MODEL=n0100 EPSILON_I18N=fr OMEGA_USERNAME="{Votre nom ici, 15 caractères max}" -j4
make MODEL=n0100 epsilon_flash
```

Important : N'oubliez pas l'argument `--recursive`, Xi a besoin de sous-modules.
Vous pouvez aussi changer le nombre de processus parallèles pendant la compilation en changeant la valeur suivant `-j`.

</details>

<details>
  <summary><b>Modèle n0110</b></summary>

```bash
git clone --recursive https://github.com/Trixciel/Xi.git
cd Xi
git checkout omega-master
make clean
make OMEGA_USERNAME="{Votre nom ici, 15 caractères max}" -j4
make epsilon_flash
```

Important : N'oubliez pas l'argument `--recursive`, Upsilon a besoin de sous-modules.
Vous pouvez aussi changer le nombre de processus parallèles pendant la compilation en changeant la valeur suivant `-j`.

</details>

<details>
  <summary><b>Fichiers binaires</b></summary>
  
Ces fichiers peuvent être utilisés pour distribuer Upsilon (pour que tout le monde puisse le flasher via [Webdfu_Numworks](https://ti-planet.github.io/webdfu_numworks/)).

```bash
git clone --recursive https://github.com/Trixciel/Xi.git
cd Xi
git checkout omega-master
make clean
make MODEL=n0100 OMEGA_USERNAME="" -j8
make MODEL=n0100 OMEGA_USERNAME="" binpack -j8
make OMEGA_USERNAME="" -j8
make OMEGA_USERNAME="" binpack -j8
```

Important : N'oubliez pas l'argument `--recursive`, Xi a besoin de sous-modules.
Vous pouvez aussi changer le nombre de processus parallèles pendant la compilation en changeant la valeur suivant `-j`.
  
</details>

<details>
  <summary><b>Simulateur web</b></summary>
  
D'abord, installez emsdk :

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest-fastcomp
./emsdk activate latest-fastcomp
source emsdk_env.sh
```

Puis, compilez Xi :

```bash
git clone --recursive https://github.com/Trixciel/Xi.git
cd Xi
git checkout omega-master
make clean
make PLATFORM=simulator TARGET=web OMEGA_USERNAME="{Votre nom ici, 15 caractères max}" -j4
```

Le simulateur se trouve dans `output/release/simulator/web/simulator.zip`

Important : N'oubliez pas l'argument `--recursive`, Upsilon a besoin de sous-modules.
Vous pouvez aussi changer le nombre de processus parallèles pendant la compilation en changeant la valeur suivant `-j`.

</details>

<details>
  <summary><b>Simulateur 3DS</b></summary>
  
Vous aurez besoin de devkitPro et de devkitARM disponible dans votre `$PATH` (instructions [ici](https://devkitpro.org/wiki/Getting_Started) (en anglais))

```bash
git clone --recursive https://github.com/Trxciel/Xi.git
cd Xi
git checkout --recursive omega-dev
make PLATFORM=simulator TARGET=3ds -j
```

Vous pouvez ensuite copier epsilon.3dsx sur une carte SD pour l'exécuter depuis le HBC ou utiliser 3dslink pour le lancer via le réseau :

```bash
3dslink output/release/simulator/3ds/epsilon.3dsx -a <ADRESSE IP 3DS>
```

</details>

Si vous avez besoin d'aide, n'hésitez pas à rejoindre le servur discord d'Upsilon : https://discord.gg/Q9buEMduXG

<a href="https://discord.gg/Q9buEMduXG"><p align="center"><img alt="Omega Banner Discord" src="https://user-images.githubusercontent.com/12123721/86287349-54ef5800-bbe8-11ea-80c1-34eb1f93eebd.png" /></p></a>
---

## Liens utiles
* [Upsilon external (pour installer des applications supplémentaires et des fonds d'écran)](https://lauryy06.github.io/Upsilon-External/)
* [Documentation d'ulab](https://micropython-ulab.readthedocs.io/en/latest/)

## Contribution

Pour contribuer, merci de lire le [Wiki d'Omega](https://github.com/Omega-Numworks/Omega/wiki/Contributing), les mêmes règles s'appliquent ici.

## Les autres projets

Les anciens projets d'Omega, avant sa fermeture, qui ont été utilisés pour ce projet

* [Omega Themes](https://github.com/Omega-Numworks/Omega-Themes)
* [Omega Website](https://github.com/Omega-Numworks/Omega-Website)
* [Omega RPN `APP`](https://github.com/Omega-Numworks/Omega-RPN)
* [Omega Atomic `APP`](https://github.com/Omega-Numworks/Omega-Atomic)
* [Omega Design](https://github.com/Omega-Numworks/Omega-Design)
* [Omega Discord Bot](https://github.com/Omega-Numworks/Omega-Discord-Bot)
* [Omega App Template `BETA`](https://github.com/Omega-Numworks/Omega-App-Template)
* [External Apps](https://github.com/Omega-Numworks/External-Apps)

## À propos d'Epsilon

Xi est un fork d'Upsilon, qui vise à créer quelques fonctionnalités utiles pour les étudiants dans le supérieur.
  
Upsilon est un fork d'Omega, visant a continuer le projet des OS utilisateurs pour Numworks

Omega est un fork d'Epsilon, un système d'exploitation performant pour calculatrices graphiques. Il inclut huit applications pour les mathématiques de lycée et d'études supérieurs

Vous pouvez essayer Epsilon depuis votre navigateur sur le [simulateur en ligne](https://www.numworks.com/simulator/).

## Licence

NumWorks est une marque déposée de NumWorks SAS, 24 Rue Godot de Mauroy, 75009 Paris, France.
Nintendo est Nintendo 3DS sont des marques déposées de Nintendo of America Inc, 4600 150th Ave NE, Redmond, WA 98052, Etats-Unis.
NumWorks SAS et Nintendo of America Inc ne sont en aucun cas associés avec ce projet.

* NumWorks Epsilon est disponible sous [Lisense CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
* Omega est disponible sous [Lisense CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
* Upsilon est disponible sous [Lisense CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
* Xi est disponible sous [Lisense CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
  

## Remerciements
  
Merci aux coomunautés d'Omega et d'Upsilon de m'avoir présenté la création d'OS Numworks comme quelque chose à ma portée.
Egalement merci à Laury, car ce readme est totalement le sien avec mon nom collé par dessus.
