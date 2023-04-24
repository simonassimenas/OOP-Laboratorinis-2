
# OOP - Pirmas laboratorinis darbas

## v1.0

## Aprašymas

Ši programa skaito studentų įrašų arba paėma naudotojo įvestus įrašus, kuriuos sudaro: studento vardas, pavardė, namų darbų rezultatai ir egzamino rezultatas, ir apskaičiuoja galutinį studento balą.

Galutinis balas skaičiuojamas dvejais būdais:

1. Pasitelkiant namų darbų pažymių vidurkį.

  > GalutinisVid = 0.4 * vidurkis + 0.6 * egzaminas
  >>![CodeCogsEqn](https://user-images.githubusercontent.com/116019627/220766715-8a46ad0d-f470-46d2-bc3c-42a8ba354050.png)

2. Pasitelkiant namų darbų pažymių vidurkį medianą.

  > GalutinisMed = 0.4 * mediana + 0.6 * egzaminas
  >>![CodeCogsEqn-2](https://user-images.githubusercontent.com/116019627/220768370-a02e423c-92d2-4747-945d-c0f46beee986.png)

Apskaičiavus gautinius įvestų studentų balus, programa išveda duomenis į failą arba išspausdina studentų vardus, pavardes bei galutinius balus, kurie apskaičiuoti pasitelkiant vidurkį arba medianą.

## Failai

- library.h - antraščių failas, kuriame saugomos naudojamos bibliotekos, aprašytos klasės bei deklaruotos naudojamos funkcijos.
- main.cpp - programos failas, kuris paleidžiamas norint naudoti programą.
- addFunctions.cpp - programos failas, kuriame saugomos naudojamos funkcijos.
- makefile - aprašytos komandos naudojamos kompiliavimui ar failų valimui.


## Instrukcija

1. Paleista programa paklausia naudotojo, kurį konteinerio tipą norėtų išbandyti.

2. Programa paklausia naudotojo, kurią strategiją norėtų išbandyti.

3. Programa paklausia naudotojo ar norima skaityti failą(a) ar įvesti duomenis(b).

4.a. Naudotojas pasirenka ar nori generuoti failą.

 > - Pasirinkus "Ne" programa toliau pereina į 4 instrukcijos žingsnį.
 > - Pasirinkus "Taip" programa toliau pereina į 3 instrukcijos žingsnį.

5.a. Naudotojas įveda norimų sugeneruoti studentų skaičių ir paspaudžia "enter" klavišą.

 > - Programa paklausia ar naudotojas nori sugeneruoti dar vieną failą, jei taip grįžtama į 3 instrukcijos žingsnį.

6.a. Naudotojas įveda failo pavadinimą ir paspaudžia "enter" klavišą.

7.a. Programa išveda kiekvieno etapo laiką bei išveda kada duomenys buvo perskaityti, surūšiuoti ir įrašyti.

 > - Nepavykus atidaryti failo programa stabdoma ir į ekraną išvedama, jog nepavyko atidaryti failo.

4.b. Paleista programa paklausia naudotojo ar bus skaičiuojamas vidurkis, ar mediana.

5.b. Naudotojas pasirenka ar nori pildyti įrašą. Pasirinkus nepradėti programa sustabdoma.

6.b. Naudotojas įveda studento vardą ir pavardę.

7.b. Programa paklausia naudotojo ar jis norėtų studento pažymius įvesti ranka, ar sugeneruoti automatiškai. Leidžiami įvesti pažymiai turi būti intervale nuo 0 iki 10. "0" reiškia, jog darbas nebuvo atsiskaitytas.

 > - Pasirinkus rankinį įvedimą naudotojas įvedą namų darbų pažymius. Kiekvienas įvedimas turi būti atskirtas klavišo "Enter" paspaudimu. Įvedimą užbaigti galima įvedus "33" ir paspaudus "Enter" klavišą. Baigus namų darbų įvedimą naudotojas įveda studento egzamino pažymį.
 > - Pasirinkus automatinį pažymių generavimą programa paprašo naudotojo įvesti pažymių skaičių(į šį skaičių neįeina egzamino pažymys).

8.b. Programa išveda, jog duomenys buvo įrašyti irpaklausia naudotojo ar jis norėtų pildyti dar vieną įrašą.

 > - Pasirinkus "Ne" programa stabdoma ir išvedami įvesti įrašų duomenys.
 > - Pasirinkus "Taip" grįžtama į 3 instrukcijos žingsnį.

## Makefile

- "make install" - sukuria visus programos failus ir juos instaliuoja.
- "make clean" - išvalo visus "instaliuotus" failus bei "vargasi.txt" ir "saunuoliai.txt".
- "make cleanf" - išvalo visus "instaliuotus" failus.
- "make cleanres" - išvalo "vargasi.txt" ir "saunuoliai.txt" failus.
- "make txt" - išvalo visus .txt failus.


## Veikimo greitis

  Bandymams naudotas namų darbų skaicius - 10.

### Programos veikimo greitis

  | Įrašų kiekis 	| Etapas                                           	| Trukmė (s) 	|
  |--------------	|--------------------------------------------------	|------------	|
  | 1000         	| Failo nuskaitymas                                	| 0.007856   	|
  |              	| Atskyrimas ir rūšiavimas (pagal galutinį pažymį) 	| 0.000013   	|
  |              	| Rūšiavimas (dvi grupės - vardais)                	| 0.000369   	|
  |              	| Rašymas į failus                                 	| 0.001619   	|
  |              	| Bendras laikas                                   	| 0.009857   	|
  |              	|                                                  	|            	|
  | 10000        	| Failo nuskaitymas                                	| 0.052215   	|
  |              	| Atskyrimas ir rūšiavimas (pagal galutinį pažymį) 	| 0.000198   	|
  |              	| Rūšiavimas (dvi grupės - vardais)                	| 0.002544   	|
  |              	| Rašymas į failus                                 	| 0.009154   	|
  |              	| Bendras laikas                                   	| 0.064111   	|
  |              	|                                                  	|            	|
  | 100000       	| Failo nuskaitymas                                	| 0.399489   	|
  |              	| Atskyrimas ir rūšiavimas (pagal galutinį pažymį) 	| 0.001401   	|
  |              	| Rūšiavimas (dvi grupės - vardais)                	| 0.036410   	|
  |              	| Rašymas į failus                                 	| 0.091424   	|
  |              	| Bendras laikas                                   	| 0.528724   	|
  |              	|                                                  	|            	|
  | 1000000      	| Failo nuskaitymas                                	| 3.807240   	|
  |              	| Atskyrimas ir rūšiavimas (pagal galutinį pažymį) 	| 0.013938   	|
  |              	| Rūšiavimas (dvi grupės - vardais)                	| 0.368861   	|
  |              	| Rašymas į failus                                 	| 0.857484   	|
  |              	| Bendras laikas                                   	| 5.047523   	|
  |              	|                                                  	|            	|
  | 10000000     	| Failo nuskaitymas                                	| 39.56331   	|
  |              	| Atskyrimas ir rūšiavimas (pagal galutinį pažymį) 	| 0.137143   	|
  |              	| Rūšiavimas (dvi grupės - vardais)                	| 4.590920   	|
  |              	| Rašymas į failus                                 	| 7.691110   	|
  |              	| Bendras laikas                                   	| 51.98248   	|

### Failu generavimo laikas

  | Įrašų kiekis 	| Etapas            	| Trukmė (s) 	|
  |--------------	|-------------------	|------------	|
  | 1000         	| Failo generavimas 	| 0.005660   	|
  |              	|                   	|            	|
  | 10000        	| Failo generavimas 	| 0.033800   	|
  |              	|                   	|            	|
  | 100000       	| Failo generavimas 	| 0.263591   	|
  |              	|                   	|            	|
  | 1000000      	| Failo generavimas 	| 2.229450   	|
  |              	|                   	|            	|
  | 10000000     	| Failo generavimas 	| 21.74790   	|

## Greičio testavimai - skirtingos duomenų struktūros

### Testavimo sistemos parametrai

- Ram: 16 GB (VSCode paskirta - 4GB), 2133 MHz DDR3
- Procesorius: 2,4 GHz Quad-Core Intel Core i5
- Diskas: SSD

  Bandymams naudotas namų darbų skaicius - 10.

#### Duomenų nuskaitymas

  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.0855624   |
  |              	| Deque            	| 0.0088298  	|
  |              	| List             	| 0.0124063  	|
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.0544154  	|
  |              	| Deque            	| 0.0525761 	|
  |              	| List             	| 0.0734453  	|
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.4189540 	|
  |              	| Deque            	| 0.4517663 	|
  |              	| List             	| 0.5696747  	|
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 4.0794712  	|
  |              	| Deque            	| 4.1688744  	|
  |              	| List             	| 5.6560688  	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 41.594612  	|
  |              	| Deque            	| 40.667611  	|
  |              	| List             	| 56.487245  	|

#### Rūšiavimas pagal galutinį pažymį
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.0001715  	|
  |              	| Deque            	| 0.0001936  	|
  |              	| List             	| 0.0001142  	|
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.0015108  	|
  |              	| Deque            	| 0.0013057  	|
  |              	| List             	| 0.0012156  	|
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.0203581  	|
  |              	| Deque            	| 0.0143641  	|
  |              	| List             	| 0.0302812  	|
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 0.2557652  	|
  |              	| Deque            	| 0.1309522  	|
  |              	| List             	| 0.6673153  	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 2.8297531  	|
  |              	| Deque            	| 1.5065155  	|
  |              	| List             	| 10.817841  	|

#### Atskyrimas į dvi grupes
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.0000041 	|
  |              	| Deque            	| 0.0000038  	|
  |              	| List             	| 0.0000022  	|
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.0000175  	|
  |              	| Deque            	| 0.0000287  	|
  |              	| List             	| 0.0000519  	|
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.0003912  	|
  |              	| Deque            	| 0.0004935 	|
  |              	| List             	| 0.0032759  	|
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 0.0055169  	|
  |              	| Deque            	| 0.0050640  	|
  |              	| List             	| 0.0516293  	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 0.0580231  	|
  |              	| Deque            	| 0.0660971 	|
  |              	| List             	| 0.5227782  	|

#### Rūšiavimas pagal vardą
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.0003411  	|
  |              	| Deque            	| 0.0004943  	|
  |              	| List             	| 0.0005543  	|
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.0030665  	|
  |              	| Deque            	| 0.0044410  	|
  |              	| List             	| 0.0034505  	|
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.0339563  	|
  |              	| Deque            	| 0.0587231  	|
  |              	| List             	| 0.0570711  	|
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 0.4675653  	|
  |              	| Deque            	| 0.6451472  	|
  |              	| List             	| 0.5601956  	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 4.7315312  	|
  |              	| Deque            	| 8.1283533  	|
  |              	| List             	| 6.5041133  	|

#### Testavimo rezultatai

  Deque duomenų struktūros naudojimas šiai programai efektyviausias, kadangi testuojant atitinkamus šios programos etapus ji atliko darbą greičiausiai. Didžiulį pranašumą suteikė labai greitas studentų surūšiavimas pagal galutinį balą.

  Verta paminėti, jog programos kodas pirma buvo rašytas nadojant **vektorius**, tad atitinkami metodai pritaikyti greitesniam vektoriaus veikimui, taip pat tai greičiausiai lemia pritaikymas prie kompiuterio architektūros.

- Pastaba: sąrašo(list) naudojimas labai stipriai sulėtina programos spausdinimą į failus nuo 100000 įrašų.

  **Duomenų nuskaitymas**:
   1. Deque
   2. Vector
   3. List

  **Rūšiavimas pagal galutinį pažymį**:
   1. Deque
   2. Vector
   3. List

  **Atskirimas į dvi grupes**:
   1. Vector
   2. Deque
   3. List

  **Rūšiaviams pagal vardą**:
   1. Vector
   2. List
   3. Deque

  **Pagal bendrą greitį**:
   1. Vector
   2. Deque
   3. List
  
## Skirtingų atskirimo metodų palyginimas

- Partition - metodas vector ir deque konteinerių tipams.
- Find if - metodas list konteinerių tipui.
- Single - originalus ir naujas konteineris.
- Split - du nauji konteineraiai.

### Vector

  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Partition        	| 0.0000196 	|
  |              	| Single           	| 0.0001953  	|
  |              	| Split            	| 0.0002674  	|
  |              	|                  	|            	|
  | 10000        	| Partition        	| 0.0000765 	|
  |              	| Single           	| 0.0019678  	|
  |              	| Split            	| 0.0019813  	|
  |              	|                  	|            	|
  | 100000       	| Partition        	| 0.0014179 	|
  |              	| Single           	| 0.0105016  	|
  |              	| Split            	| 0.0179358  	|
  |              	|                  	|            	|
  | 1000000     	| Partition        	| 0.0133609 	|
  |              	| Single           	| 0.0911167  	|
  |              	| Split            	| 0.1648474  	|
  |              	|                  	|            	|
  | 10000000     	| Partition        	| 0.1116033  	|
  |              	| Single           	| 0.9240467 	|
  |              	| Split            	| 1.7720802  	|

### Deque

  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Partition        	| 0.0000283 	|
  |              	| Single           	| 0.0000441 	|
  |              	| Split            	| 0.0000981  	|
  |              	|                  	|            	|
  | 10000        	| Partition        	| 0.0002024 	|
  |              	| Single           	| 0.0003569  	|
  |              	| Split            	| 0.0008617  	|
  |              	|                  	|            	|
  | 100000       	| Partition        	| 0.0015194 	|
  |              	| Single           	| 0.0060992  	|
  |              	| Split            	| 0.0085026 	|
  |              	|                  	|            	|
  | 1000000     	| Partition        	| 0.0192062 	|
  |              	| Single           	| 0.0724808  	|
  |              	| Split            	| 0.0735761  	|
  |              	|                  	|            	|
  | 10000000     	| Partition        	| 0.1705511  	|
  |              	| Single           	| 0.6913876 	|
  |              	| Split            	| 0.7532513  	|

### List

  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Find if         	| 0.0002126 	|
  |              	| Single           	| 0.0000829  	|
  |              	| Split            	| 0.0000845  	|
  |              	|                  	|            	|
  | 10000        	| Find if         	| 0.0013825 	|
  |              	| Single           	| 0.0008285  	|
  |              	| Split            	| 0.0009435  	|
  |              	|                  	|            	|
  | 100000       	| Find if         	| 0.0333887 	|
  |              	| Single           	| 0.0103249  	|
  |              	| Split            	| 0.0113262  	|
  |              	|                  	|            	|
  | 1000000     	| Find if         	| 0.7193911 	|
  |              	| Single           	| 0.1099722  	|
  |              	| Split            	| 0.1050686  	|
  |              	|                  	|            	|
  | 10000000     	| Find if         	| 10.702866  	|
  |              	| Single           	| 1.1143877 	|
  |              	| Split            	| 1.0205761  	|

### Testavimo rezultatai

#### Vector

**Partition** metodas buvo greičiausias atskiriant vektorius į dvi grupes, kadangi susiskirstymas buvo atliekamas originaliame vektoriuje, tad programa neužtruko laiko dirbdama su nauju vektoriumi.
**Originalus ir naujas konteineris** metodas buvo 9 kartus lėtesnis už **Partition**, kadangi buvo dirbama su vienu nauju vektoriumi į kurį buvo kopijuojami duomenys atitinkantys sąlygas ir trinami iš originalaus vektoriaus.
**Du nauji konteineraiai** metodas buvo 2 kartus lėtesnis už **Originalus ir naujas konteineris**, kadangi buvo dirbama su dviejais naujais vektoriais į kuriuos buvo perkeliami duomenys.

**Atskyrimo į dvi grupes greitis**:
1. Partition metodas
2. Originalus ir naujas konteineris
3. Du nauji konteineraiai

#### Deque

**Partition** metodas buvo greičiausias atskiriant dekais į dvi grupes, kadangi susiskirstymas buvo atliekamas originaliame vektoriuje, tad programa neužtruko laiko dirbdama su nauju vektoriumi.
**Originalus ir naujas konteineris** metodas buvo 5 kartus lėtesnis už **Partition**, kadangi buvo dirbama su vienu nauju deku į kurį buvo kopijuojami duomenys atitinkantys sąlygas ir trinami iš originalaus vektoriaus.
**Du nauji konteineraiai** metodas buvo beceik identiškas **Originalus ir naujas konteineris**, nors buvo dirbama su dviejais naujais dekais į kuriuos buvo perkeliami duomenys.

**Atskyrimo į dvi grupes greitis**:
1. Partition metodas
2. Originalus ir naujas konteineris
3. Du nauji konteineraiai

#### List

**Originalus ir naujas konteineris** metodas buvo greičiausias, kadangi buvo dirbama su vienu nauju listu į kurį buvo kopijuojami duomenys atitinkantys sąlygas ir trinami iš originalaus vektoriaus.
**Du nauji konteineraiai** metodas beveik identiškas **Originalus ir naujas konteineris**, nors buvo dirbama su dviejais naujais listais į kuriuos buvo perkeliami duomenys.
**Find if** metodas buvo 10 kartų lėtesnis už **Originalus ir naujas konteineris**, kadangi buvo atliekamas naudojant daug sudėtingų operacijų bei rūšiavimą, kurie sunaudojo daug laiko.

**Atskyrimo į dvi grupes greitis**:
1. Originalus ir naujas konteineris
2. Du nauji konteineraiai
3. Find if metodas

## Versijų v1.0 ir v1.0 palyginimas

