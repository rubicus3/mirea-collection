#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long s_hash(string const &s)
{
	const int p = 31;
	const int m = 1e9 + 9;
	long long hash_value = 0;
	long long p_pow = 1;
	for (char c : s)
	{
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

int RK_search(string str, string substr)
{
	int n = str.length(), m = substr.length();

	long long hsub = s_hash(substr);
	long long hs = s_hash(str.substr(0, m));

	int k = 0;
	for (int i = 0; i < n - m + 1; i++)
	{
		k++;
		if (hs == hsub)
		{

			if (str.substr(i, m) == substr)
			{
				cout << "Сравнений: " << k << endl;

				return i;
			}
		}
		hs = s_hash(str.substr(i + 1, m));
	}
				cout << "Сравнений: " << k << endl;

	return -1;
}

void test()
{
	string s1 = "Добро пожаловать в c++: самый удобный язык для работы со строками!";
	string s2 = "Lorem ipsum dolor sit amet consectetur adipisicing elit. Neque similique perferendis sunt laudantium eius possimus ea accusamus minima dignissimos? Voluptatem fugiat rem ipsa placeat fugit удобный vel perspiciatis itaque corrupti quod illo quo ratione non magnam suscipit id nisi dolorem maxime harum nulla laborum, ut distinctio doloribus mollitia! Vitae soluta numquam animi repellat reprehenderit facere fugit odio consequatur totam fuga adipisci accusamus quidem, quisquam quos esse inventore rerum quasi exercitationem aliquam quam excepturi? Amet similique quod vitae eos nulla dicta, fugit, atque necessitatibus pariatur placeat molestias nobis temporibus! Illum harum provident quia molestias incidunt dolor reiciendis minus sint sequi quas ratione, blanditiis obcaecati veritatis, reprehenderit quis. Illo voluptatem nesciunt, ullam ipsa quod aperiam alias et sit, fugiat porro voluptates quo quis ea dolor esse possimus aspernatur laboriosam dolorem fuga consectetur. Et assumenda voluptatum ipsum itaque modi sit, doloremque eum, accusamus aliquam placeat dignissimos optio dolores quisquam deserunt sint. Sint nisi harum modi cupiditate. Pariatur ab temporibus quo ducimus tenetur fuga natus similique officia, accusantium, harum sunt. Corporis similique aperiam accusantium laudantium facilis possimus ipsum est culpa. Harum doloremque, ipsa sit maiores eum inventore iure quod illo! Adipisci repellendus nobis, natus illum provident fugit dolore quas. Tempore tenetur asperiores reiciendis iste illo, voluptatum mollitia aspernatur iusto, quas ullam unde incidunt dolore. Cupiditate asperiores provident ullam excepturi iste dignissimos alias earum doloribus quibusdam, numquam amet saepe labore dolores beatae accusantium. Iure accusamus autem possimus laboriosam ratione sed nihil placeat error delectus, repudiandae iste nobis in. Debitis repellendus cumque nam aut ipsam optio vero minus recusandae totam, atque nulla suscipit at voluptatum vitae odio magnam quos nemo dolorem excepturi iusto voluptate earum animi? Quo eum voluptatem quidem asperiores a quos, et deserunt totam maiores reiciendis est alias tenetur soluta, illum nemo labore dignissimos ad non! Sit officia expedita quae, tempore deleniti sequi distinctio placeat cupiditate? Odit impedit, aperiam commodi facilis voluptatem eaque ullam optio rerum vitae repudiandae ut deleniti officiis tempora amet? Architecto blanditiis, quas sapiente ad nemo quidem eos, exercitationem, quia cupiditate culpa eaque. Ex ducimus incidunt odio officia, tempore excepturi nesciunt quasi quos accusamus aspernatur eveniet itaque commodi, dolores illo ipsam accusantium quas quidem reiciendis delectus consequuntur neque! Sequi possimus expedita, mollitia deleniti odio natus recusandae odit nisi quisquam, molestiae, corporis soluta. Sunt aut rerum nesciunt eaque eligendi, consequatur atque, cum velit eum fugit, excepturi dolorum consequuntur. Optio commodi deserunt tempora odit ab magni quidem dolorum quos saepe explicabo consectetur omnis corrupti aperiam, et libero. Aut saepe rem voluptates deleniti unde eius doloremque labore vel pariatur laudantium, doloribus, dolore officiis iusto. Consectetur ipsa, ea nisi, omnis culpa consequuntur inventore expedita ad deleniti id iusto blanditiis ab ratione odio, esse asperiores ullam temporibus tenetur libero voluptas. Odit atque ratione reiciendis? Velit, itaque nam consequatur, voluptatum, minima obcaecati accusantium eveniet tempore rerum eius reprehenderit ut delectus quisquam veniam tempora aperiam amet? Error quia neque alias consequuntur recusandae aperiam sequi, fuga exercitationem molestiae? Aliquid nostrum pariatur amet nulla natus exercitationem tempora at. Ipsum atque ratione eveniet at quas, magnam iusto corrupti vitae, consequatur esse ut labore quo commodi natus voluptate facere quae illum? Nam blanditiis, dolorum cum atque soluta rerum voluptate impedit repudiandae incidunt necessitatibus nostrum corrupti fugit consequuntur reiciendis nisi vero minima earum laboriosam quod? Rerum magni doloremque et labore vitae consectetur veniam reprehenderit facere? Assumenda ratione consequuntur expedita dignissimos molestias, impedit maiores quisquam unde. Earum quisquam nostrum dicta, modi similique cupiditate sunt exercitationem fugit, architecto dolore dolor commodi rerum sed temporibus ipsum recusandae ea, quasi debitis enim quae! Deserunt unde, eum repellendus atque similique perspiciatis vero fugit quod illo veniam corporis possimus incidunt distinctio saepe suscipit dolorem esse officia in recusandae laboriosam non veritatis! Iste facilis animi odio voluptate? Exercitationem accusantium aliquam illo ex perspiciatis ipsum eveniet suscipit sit repellat ipsa quia dolorem odit odio voluptatem cumque architecto cum amet, possimus optio? Vel molestiae deserunt, fugiat nam ea quisquam? Odit nam dolorem ex iusto molestiae atque ad voluptatem nihil dolorum, dolor doloribus maxime commodi laborum laboriosam libero. Delectus necessitatibus architecto quisquam iste commodi quas quidem aliquam eum in quibusdam fugiat, quod enim quis voluptates praesentium cumque repudiandae numquam nostrum illo ab. Provident molestiae fuga excepturi vel cumque, corrupti sit modi beatae esse eveniet? Voluptas maxime tempora et! Esse minus modi, totam tempora quas, maiores nihil eos iste necessitatibus adipisci porro facere minima tempore placeat ab expedita accusamus atque sed assumenda! Autem aliquam obcaecati quaerat doloremque! Quasi culpa et in tempora quisquam praesentium sint dicta at voluptas voluptates nobis nam, ullam suscipit architecto possimus expedita optio vitae rerum aliquid. Suscipit, quo, praesentium et tempore pariatur odit corporis vel dolorem deleniti numquam laboriosam earum dicta, non aliquid perspiciatis similique doloremque aperiam deserunt inventore! Iusto sit consequuntur perspiciatis culpa voluptas! Qui beatae alias blanditiis eveniet. Quo facilis deserunt debitis quos necessitatibus pariatur in rem libero quod natus totam, magnam nostrum unde praesentium vitae culpa recusandae iste soluta. Distinctio consequatur doloribus dicta laudantium molestias odit laborum nulla ab cumque necessitatibus sunt eos iste ut, sapiente magni dolorem quibusdam ducimus ex fuga repellendus doloremque. Sunt accusamus beatae labore tempora aut ipsam accusantium quo expedita quas numquam ut illo exercitationem, facilis possimus! Eligendi, odit accusantium. Placeat animi aliquam dolores officia quidem repudiandae ut in tempora corporis error illo soluta aliquid repellendus quia eligendi, quae deserunt, commodi minima recusandae dicta? Saepe harum atque enim quas? Labore debitis, numquam quod facilis quis consectetur omnis possimus nobis cum autem fuga sint, nostrum quidem officiis commodi laborum quaerat dolor iusto maiores similique, sed nam natus? Pariatur exercitationem error ratione qui distinctio minus necessitatibus illum? Ea sed rerum delectus veritatis quibusdam dolore modi dignissimos deserunt quia molestiae provident eveniet natus, eligendi vel dolorum dolor omnis quae et ad doloribus sapiente officia minus unde! Voluptas, molestiae aut labore sapiente facere nam accusantium ad neque qui dignissimos omnis voluptate natus nostrum fuga atque ut facilis corporis ullam eligendi alias. Facere at veniam qui illo numquam voluptatibus nostrum. Perspiciatis voluptatem dolores odio, quisquam alias pariatur officiis omnis quas laudantium sed, nemo deserunt deleniti similique quam nihil aliquam autem nesciunt illo. Ad ipsa nisi, dolores nostrum ipsam quaerat.";
	string sub1 = "удобный";
	string sub2 = "хръэжщц";

	// Initializing
	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start).count();

	cout << endl
		 << "Малый, удачный" << endl;
	start = high_resolution_clock::now();
	stop = high_resolution_clock::now();
	RK_search(s1, sub1);
	duration = duration_cast<nanoseconds>(stop - start).count();
	cout << "Время: " << duration << " нс." << endl;

	cout << endl
		 << "Большой, удачный" << endl;
	start = high_resolution_clock::now();
	stop = high_resolution_clock::now();
	RK_search(s2, sub1);
	duration = duration_cast<nanoseconds>(stop - start).count();
	cout << "Время: " << duration << " нс." << endl;

	cout << endl
		 << "Малый, неудачный" << endl;
	start = high_resolution_clock::now();
	stop = high_resolution_clock::now();
	RK_search(s1, sub2);
	duration = duration_cast<nanoseconds>(stop - start).count();
	cout << "Время: " << duration << " нс." << endl;

	cout << endl
		 << "Большой, неудачный" << endl;
	start = high_resolution_clock::now();
	stop = high_resolution_clock::now();
	RK_search(s2, sub2);
	duration = duration_cast<nanoseconds>(stop - start).count();
	cout << "Время: " << duration << " нс." << endl;
}

int main()
{
	test();
	// cout << endl;

	string s = "Добро пожаловать в c++: самый удобный язык для работы со строками!";
	string sub = "бный язык дл";

	int found = RK_search(s, sub);

	if (found != -1)
	{
		cout << "Подстрока \"" << sub << "\" найдено на " << found << " позиции." << endl;
	}
	else
		cout << "Подстрока \"" << sub << "\" не найдено" << endl;
}