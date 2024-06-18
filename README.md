<!-- Improved compatibility of Вернуться наверх link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<!-- PROJECT LOGO -->
<br />
<div align="center">

<h3 align="center">Проект Онегин</h3>

  <p align="center">
    Программа для сортировки текста по строкам
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Таблица содержимого</summary>
  <ol>
    <li>
      <a href="#about-the-project">О проекте</a>
    </li>
    <li>
      <a href="#getting-started">Начало работы</a>
    </li>
    <li><a href="#usage">Примеры использования</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## О проекте

Проект Онегина был создан в рамках курса системного программирования и компиляторных технологий *И.Р. Дединского* на 1 курсе бакалавриата **МФТИ**. Целью проекта является показать умение работать с содержимым файлов и сортировками. Данная версия проекта реализована с использованием сортировки **quick sort** на локализации UTF-8 (поддержка русского и английского языков). Программа выполняет сортировку текста по строкам, в алфавитном порядке с начала и конца строк:

#### Оригинальый текст:
```
  Буся
  Кузя
  Бася
  Ася
```
#### Текст, сортированный с начала:
```
  Ася
  Бася
  Буся
  Кузя
```
#### Текст, сортированный с конца:
```
  Кузя
  Ася
  Бася
  Буся
```


<p align="right">(<a href="#readme-top">Вернуться наверх</a>)</p>


<!-- GETTING STARTED -->
## Начало работы

Чтобы воспользоваться программой, выполните следующие шаги:

1. Склонируйте репозиторий в свою среду vscode:
   ```sh
   git clone git@github.com:yayamayaya/onegin.git
   ```
2. Запустите сборку проекта vscode (стандартная комбинация клавиш - **Ctrl+Shift+B**)
3. Чтобы запустить программу, вам нужно два текстовых файла: в одном файле будет содержаться оригинальный текст, который нужно отсортировать, в другой же файл будет записываться сам отсортированный текст:
   ```sh
    make out=... in=...
   ```
   где вместо многоточий у **out** ставится имя файла, куда будет записан отсортированный текст(файл, куда), а у **in** имя файла, где записан оригинальный текст(файл, откуда)

<p align="right">(<a href="#readme-top">Вернуться наверх</a>)</p>



<!-- USAGE EXAMPLES -->
## Примеры использования

Яркий пример использования можно найти среди самих файлов программы: в файле **out.txt** записана поэма Евгений Онегин, отсортированная в прямом и обратном алфавитном порядке по строкам

<p align="right">(<a href="#readme-top">Вернуться наверх</a>)</p>


