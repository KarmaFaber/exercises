#!/bin/bash

git status

git add .

read -p "Introduce el comentario para el commit: " commit_message

git commit -m "$commit_message"

git push

