# Zamek do serwerowni

## Cel projektu

Automatyzacja otwierania drzwi w serwerowni

## Spis sprzętu

- Arduino
- Przewody 
- Klawiatura 4x4
- [Czytnik RFID/NFC](https://pl.aliexpress.com/item/1005007506031691.html?src=google&pdp_npi=4%40dis%21PLN%2114.33%2114.33%21%21%21%21%21%40%2112000041059250804%21ppc%21%21%21&src=google&albch=shopping&acnt=708-803-3821&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pl1005007506031691&ds_e_product_merchant_id=459821515&ds_e_product_country=PL&ds_e_product_language=pl&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19735245762&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=EAIaIQobChMI_bDHtYuziQMVM7GDBx2hrTkEEAQYAiABEgJKZfD_BwE)
- [Ekran Oled](https://www.ceneo.pl/98858951?fto=327704793&se=XJmd8pwd-h5F7aphGZA8u3fmh46Jrlju&gad_source=1&gclid=EAIaIQobChMIpuWGuI2ziQMVJp1oCR2PKR08EAQYBCABEgJWifD_BwE)

## Kod & Wyjaśnienie

## Jak podłączyć

### Podłączenie Arduino

1. Pobierz projekt 
- Za pomocą [linka](https://github.com/kubixgames05/Zamek/archive/refs/heads/master.zip)
- Za pomocą komendy
```shell
git clone https://github.com/kubixgames05/Zamek --recursive
```
2. Pobierz i zainsstaluj [Arduino IDE](https://www.arduino.cc/en/software) 
3. Otwórz projekt i doinstaluj potrzebne biblioteki
4. Edytuj kod zmieniając domyślne hasło

### Podłączenie przewodów

1. Odłącz arduino od zasilania 
2. Podłącz przewody według zdjęcia 
3. Podłącz arduino do komputera za pomocą kabla USB

### Wgrywanie Programu 

1. W edytorze sprawdz poprawność kodu 
2. Prześlij kod do arduino 

### Sprawdzenie poprawności działania kodu

1. Otwórz Monitor Portu Szeregowego na częstotliwości ```9600```
2. Naciśnij jeden z klawiszy na klawiaturze i zaobserwój dane wyjściowe
