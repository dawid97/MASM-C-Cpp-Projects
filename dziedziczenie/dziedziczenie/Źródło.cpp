//konstruktor kopiujacy(klasa pochodna)
Tautomobil(const Tautomobil&wzorzec) :Tpojazd(wzorzec)
{
	stan_licznika = 0;
	kolor_karoserii = wzorzec.kolor_karoserii;
}

//konstruktor przenoszacy(klasa pochodna)
Tautomobil(Tautomobil&&odzysk)::Tpojazd(move(odzysk))
{
	stan_licznika = 0;
	kolor_karoserii = odzysk.kolor_karoserii;
}

//kopiuj¹cy operator przypisania(klasa pochodna)
Tautomobil&operator=(const Tautomobil&wzor)
{
	if (this != &wzor)
	{
		Tpojazd::operator=(wzor);
		kolor_karoserii = wzor.kolor_karoserii;
		stan_licznika = wzor.stan_licznika;
	}
	return*this;
}

//przenoszacy operator przypisania(klasa pochodna)
Tautomobil&operator=(Tautomobil&&wzorcowy)
{
	if (this != &wzorcowy)
	{
		Tpojazd::operator=(move(wzorcowy));
		kolor_karoserii = wzorcowy.kolor_karoserii;
		stan_licznika = wzorcowy.stan_licznika;
	}
	return*this;
}

//konstruktor kopijacy
Tpersona(const Tpersona&wzor)
{
	ile_prob = wzor.ile_prob;
	adr_nazwiska = new string;
	*adr_nazwiska = *(wzor.adr_nazwiska);
	tabl_czasow_prob = new double[max.elem];
	for (int i = 0; i < max.elem; i++)
	{
		tabl_czasow_prob[i] = wzor.tabl_czasow.prob[i];
	}
}

//konstruktor przenoszacy
Tpersona(Tpersona&&inny)
{
	ile_prob = inny.ile_prob;
	adr_nazwiska = inny.adr_nazwiska;
	inny.adr_nazwiska = nullptr;
	tabl_czasow_prob = inny.tabl_czasow_prob;
	inny.tabl_czasow_prob = nullptr;
}

//przenoszacy operator przypisania
Tpersona&operator=(Tpersona&&inny)
{
	if (&inny != this)
	{
		delete[] tabl_czasow_prob;
		delete adr_nazwiska;
		ile_prob = inny.ile_prob;
		adr_nazwiska = inny.adr_nazwiska;
		tabl_czasow_prob = inny.tablica_czasow_prob;

		inny.adr_nazwiska = nullptr;
		inny.tabl_czasow_prob = nullptr;
	}
	return*this;
}

//kopiujacy operator przypisania
Tpersona&operator=(const Tpersona&wzor)
{
	if (&wzor != this)
	{
		delete[] tabl_czasow_prob;
		delete adr_mazwiska;
		ile_prob = wzor.ile_prob;
		adr_nazwiska = new string;
		*(adr_nazwiska) = *(wzor.adr_nazwiska);
		tabl_czasow_prob = new double[max_elem];
		for (int i = 0; i < max_elem; i++)
		{
			tabl_czasow_prob[i] = wzor.tabl_czasow_prob[i];
		}
	}
	return*this;
}

