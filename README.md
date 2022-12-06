# ft_president

# Pour les gouverner tous

Ça y est, vous avez été élu à la présidence. Vous maintenant réaliser votre rêve : les gouverner tous !
Mais vous vous retrouvez cependant face à un problème, il y a beaucoup trop de régions et vous avez du mal à les retenir, vous voulez donc les fusionner. Mais voilà qu'un autre problème surgit : la colère gronde dans le pays, il y a beaucoup trop d'écart de PIB, et certaines régions sont bien plus pauvres que d'autre, il faudrait que vos nouvelles régions équilibrent les richesses. Hélas, dans votre équipe de développeurs, il n'y a aucun élève de l'école 42... Vous allez donc devoir vous débrouiller tout seul, et ressortir vos livres d'algorythmie !

# Votre mission

Votre programme devra compiler avec un makefile, l'executable devra s'appeller <ft_president>, il recevra en premier argument un fichier, qui contiendra l'ensemble des régions, puis en second argument un fichier, qui recevra la réponse, et en troisième argument un nombre, qui correspondra au nombre de régions voulu. 
  
  La commande s'executera ainsi : 
	
```./ft_president <nom de fichier 1> <nom de fichier 2> <nombre de régions>```

  Chaque ligne du premier fichier se comporteront ainsi :
	
```<nom de région 1> : <PIB de la région> : <région touchée 1>-<région touchée 2>-<région touchée trois>```

  Chaque ligne du second fichier devront se comporter ainsi :
	
```<nom de fusionnée région 1>-<nom de région fusionnée 2>-<nom de région fusionnée 3>```

Votre programme devra écrire le nombre de régions souhaités, dans le fichiers de sorties, s'il ne trouve pas le bon nombre de régions, il devra écrire "Error" suivit d'un retour à la ligne. Vous avez le droit de vous servir de la sortie standard à votre guise. Vous devrez suivre deux règles :
  Pour fusionner deux régions entre elles, elles doivent se toucher.
  Le résultat que vous donnez doit avoir l'écart-type le plus bas.
Si une de ces conditions n'est pas vérifiée, votre résultat sera faux.


  Le parsing ne sera pas testé, le but est de réaliser l'execution, les valeurs au-delà de int ne seront pas testées.
  Le graphe réalisé par ces régions ne sera pas connexe, pas orienté, il n'y aura pas de boucle, ni d'arrètes multiples, l'ordre du graphe ne dépassera pas 30, et il ne sera pas forcément complet.

  Une vingtaine de tests seront faits, dont la moitié sera avec le nombre de régions souhaités à 2.
  
  # Votre récompense
  
  Les trois meilleurs participants auront un au choix
  * 2 cookies par membre
  * un autographe d'une star de l'Ecole
  * 2 figurines de Noël.
  
  Si deux groupes ont le même score, alors ils seront départagés sur le temps.
