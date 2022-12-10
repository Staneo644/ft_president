# ft_president

# Pour les gouverner tous

Ça y est, vous avez été élu à la présidence. Vous pouvez maintenant réaliser votre rêve : les gouverner tous !
Mais vous vous retrouvez cependant face à un problème, il y a beaucoup trop de régions et vous avez du mal à les retenir, vous voulez donc les fusionner. Mais voilà qu'un autre problème surgit : la colère gronde dans le pays, il y a beaucoup trop d'écart de PIB, et certaines régions sont bien plus pauvres que d'autre, il faudrait que vos nouvelles régions équilibrent les richesses. Hélas, dans votre équipe de développeurs, il n'y a aucun élève de l'école 42... Vous allez donc devoir vous débrouiller tout seul, et ressortir vos livres d'algorithmie !

# Votre mission

Votre programme devra s'exécuter avec un script bash, qui s'appellera <ft_president.sh>, il recevra en premier argument un fichier d'entrée, qui contiendra l'ensemble des régions, puis en second argument un fichier de sortie, qui recevra la réponse, et en troisième argument un nombre, qui correspondra au nombre de régions voulu.
  
  La commande s'exécutera ainsi : 
	
```./ft_president.sh <nom du fichier d'entrée> <nom du fichier de sortie> <nombre de régions>```

  Chaque ligne du fichier d'entrée se comporteront ainsi :
	
```<nom de région 1> : <PIB de la région> : <région touchée 1>-<région touchée 2>-<région touchée trois>```

  Chaque ligne du fichier de sortie devront se comporter, pour illustrer les régions fusionnées :
	
```<nom de région 1>-<nom de région 2>-<nom de région 3>```

Vous avez dans ce git des exemples des fichiers d'entrée et de sortie, avec le résultat de la commande

```./ft_president.sh exempleRegion.txt resultat.txt 6```

Votre programme devra écrire le nombre de régions souhaitées, dans le fichier de sorties, s'il ne trouve pas le bon nombre de régions, il devra écrire "Error" suivi d'un retour à la ligne. Vous avez le droit de vous servir de la sortie standard à votre guise. Vous devrez suivre deux règles :
  * Pour fusionner deux régions entre elles, elles doivent se toucher.
  * Le résultat que vous donnez doit avoir l'écart-type le plus bas.

Si une de ces conditions n'est pas vérifiée, votre résultat sera faux.


  Le parsing ne sera pas testé, le but est de réaliser l'exécution, les valeurs au-delà de int ne seront pas testées.
  Le graphe réalisé par ces régions ne sera pas connexe, pas orienté, il n'y aura pas de boucle (une région ne peut pas se toucher), ni d'arêtes multiples, l'ordre du graphe ne dépassera pas 30, et il ne sera pas forcément complet.

  42 tests seront faits, dont la moitié avec le nombre de régions souhaités à 2.
  
  Un fichier de parsing en C est donné avec le git, si vous le souhaitez, vous pouvez vous en servir, vous pouvez aussi le modifier à votre guise. 
  
  # Le rendu
  
  Vous allez créer votre propre git, et vous enverrez le lien à 'Staneo644', le projet devra être rendu dimanche, à 23h41.
  
  
  # Votre récompense
  
  La cérémonie des récompenses aura lieu mardi après-midi.
  
  Tout ceux qui auront validé tous les tests recevront leur Diplôme National de Souveraineté (DNS).
  
  Les trois meilleurs participants auront au choix
  * 2 cookies par membre, ou une pinte, suivant les goûts
  * un autographe d'une star de l'Ecole
  * 2 figurines de Noël.
  
  Si deux groupes ont le même score, alors ils seront départagés sur la somme du temps d'execution de chacun des tests.
