# cpp-image-processing

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://lordmorgoth.net/)

## Vue d'ensemble

Notre application permet d’effectuer différents traitements sur une image source. L’utilisateur peut définir les différents traitements qu’il souhaite appliquer à son image via un menu qu’il lui permettra d’effectuer sa sélection. L’utilisateur peut prévisualiser l’image avant d’enregistrer son image avec les différents traitements appliquées à celle-ci. Si l’utilisateur vient à commettre une erreur lors de son choix, l’application lui offre le choix de revenir autant de fois en arrière que possible.

## Traitements d'image disponibles

**▪ Filtrage :** 
- Filtre médian
- Filtre gaussien

**▪ Dérivation :**
- Calcul du gradient dans une image (Sobel)

**▪ Opérations de morphologie mathématique :**
- Dilatation 
- Érosion

**▪ Détection de contours :**  
- Application d’un détecteur de contours « Canny »

**▪ Segmentations d’images :**  
- Opérations de seuillages 
- Segmentation par croissance de région

## Diagramme UML 

![](https://yuml.me/tomrh/uml.png)

## Utilisation de l'application

Toutes les actions décrites ci-dessous s’effectuent en indiquant le chiffre correspondant à votre choix dans l’application. La liste des actions est disponible dans le menu à partir du moment où le chargement de l’image s’est bien déroulé.

**▪ 1ère étape :**

À l’ouverture de l’application, vous devez spécifier le chemin d’accès à l’image, si l’application rencontre un quelconque problème lors de l’ouverture de l’image, elle vous demandera à nouveau de spécifier le chemin d’accès jusqu’à ce que celui-ci soit correct.

**▪ 2ème étape :**

Une fois l’image chargée dans l’application, vous aurez la possibilité d’appliquer les différents traitements disponibles à l’image que vous avez indiqué. Certains traitements vous demanderont de spécifier certains paramètres afin de mieux cibler votre requête.
Vous pouvez consulter à tout moment, un aperçu des traitements que vous appliquez à votre image.
De plus, si vous effectué un traitement par erreur, vous avez toujours la possibilité de revenir au traitement précédent via le menu de l’application autant de fois que nécessaire.

**▪ 3ème étape :**

Une fois avoir appliqué les différents traitements à votre image, vous avez la possibilité d'enregistrer l’image à une adresse quelconque dont vous avez la possibilité de spécifier.
