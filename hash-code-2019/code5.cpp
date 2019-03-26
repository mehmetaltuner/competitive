#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009
#define endl '\n'

using namespace std;

typedef long long int lli;


lli intersect(set <string> s1, set <string> s2){
	set <string> temp;
	for(auto s: s1){
		temp.insert(s);
	}
	for(auto s: s2){
		temp.insert(s);
	}

	return s1.size() + s2.size() - temp.size();
}

class Photo{
	public:
		bool horizontal;
		set <string> tags;
		lli index;
};


class Slide{
	public:
		Slide(){
			p1 = NULL;
			p2 = NULL;
			next = NULL;
			back = NULL;
		}
		Photo *p1;
		Photo *p2;
		void change_p1(Photo *);
		void change_p2(Photo *);

		set <string> tags();

		Slide *next;
		Slide *back;
};


set <string> Slide::tags(){
	set <string> temp;
	for(auto t: p1->tags){
		temp.insert(t);
	}

	if(p2)
		for(auto t: p2->tags){
			temp.insert(t);
		}

	return temp;
}

void Slide::change_p1(Photo *p){
	p1 = p;
	return;
}

void Slide::change_p2(Photo *p){
	p2 = p;
	return;
}

lli hesap(Slide *s1, Slide *s2){
	
	lli x = intersect(s1->tags(), s2->tags());

	lli y = s1->tags().size() - x;

	lli z = s2->tags().size() - x;

	return min({x, y, z});
}
vector<Slide *> ver(vector<Photo *> v)
{
    int a = v.size();
    vector<bool> used(a, 0);
    int toplam = 0;
    vector<Slide *> r;
    while(v.size()>1)
    {
        if(v.size()%1000==0)cerr<<"vers "<<v.size()<<endl;
        int i1 = rand() * 10 + rand();
        i1 = abs(i1);
        i1 %= (int)v.size();
        Photo * p= v[i1]; 
        v.erase(v.begin() + i1);

        int minn = 10000;
        int minn_i = -1;
        for(int j =0; j<50; j++)
        {
            int index = rand() * 10 + rand();
            index = abs(index);
            index %= (int)v.size();

            int tm = intersect(p->tags, v[index]->tags);

            if(tm < minn)
            {
                minn = tm;

                minn_i = index;

            }
        }

        Slide * sss = new Slide;
        sss->change_p1(p);
        sss->change_p2(v[minn_i]);
        v.erase(v.begin() + minn_i);

        r.push_back(sss);

    }

    return r;

}
int main(){
	ios::sync_with_stdio(0);
        srand(time(0));
	lli n;
	cin >> n;

	Slide *last_vertical = new Slide;
	set <Slide *> s;
    vector <Slide *> sv;

    vector <Photo *> verticals;
	for(int i=0; i<n; i++){
		char v;
		int tag_count;

		cin >> v >> tag_count;

		Photo *nphoto = new Photo;
		nphoto->horizontal = v == 'H';
		nphoto->index = i;

		for(int j=0; j<tag_count; j++){
			string tag;
			cin >> tag;
			nphoto->tags.insert(tag);
		}


		if(nphoto->horizontal){
			Slide *newslide = new Slide;
			newslide->change_p1(nphoto);
			s.insert(newslide);
            sv.pb(newslide);
		}else{
		
            verticals.push_back(nphoto);

		}

	}

	cerr << "end ipnut" << endl;

    
    vector<Slide *> vers = ver(verticals);

    for(auto a: vers)
    {
        s.insert(a);
        sv.pb(a);
    }


	vector <bool> used(n+5, false);
	
	used[0] = 1;
	set<Slide *> us;

	Slide * slides;
	Slide * last;
	slides = sv[0];
    last = slides;
    us.insert(sv[0]);
    s.erase(sv[0]);
	//cerr << "nul"<<(s[0] == NULL) << endl;

	Slide* max_index = 0;
	lli slide_number = sv.size();

	cerr << slide_number << endl;

    int toplam;
	for(toplam = 1; toplam < slide_number;toplam++){
		if(toplam % 1000 == 0)
			cerr <<"toplam: " << toplam << endl;

		//max_index = n+100;
		lli max_result = -1;
		lli kontrol = 0;

		for(auto aaa: s){
			// j %= slide_number;		

			// if(used[j])
			// 	continue;

			if(kontrol > 5){
				break;
			}

			lli h = hesap(last, aaa);
			kontrol++;

			if(h > max_result){
				max_result = h;
				max_index = aaa;
			}
			
		}


		//used[max_index] = 1;
        s.erase(max_index);
		last->next = max_index;
        last = max_index;
		//max_index->back = sv[i];
	
	}
	cerr << "end cal" << endl;

	Slide *temp = slides;
	cout << sv.size() << endl;
	vector <Slide *> vecslide;
	
	while(temp){
		//cerr << "loop" << endl;
		/*cout << temp->p1->index;
		if(temp->p2){
			cout << " " << temp->p2->index;
		}
		cout << endl;*/
		vecslide.pb(temp);
		temp = temp->next;
	}
	
	int size = vecslide.size();
	for(int i=1; i<size-1; i++){
		if(i % 1000 == 0)
			cerr << "vector traverse " << i << endl;

		for(int j=0; j<10; j++){
			int index = rand() * 10 + rand();
			index = abs(index);
			index %= (slide_number - 2);
			index++;	


			
			int old_sco = hesap(vecslide[i], vecslide[i-1]);
			old_sco += hesap(vecslide[i], vecslide[i+1]);

			old_sco += hesap(vecslide[index], vecslide[index-1]);
			old_sco += hesap(vecslide[index], vecslide[index+1]);

			int new_sco = hesap(vecslide[index], vecslide[i-1]);
			new_sco += hesap(vecslide[index], vecslide[i-1]);

			new_sco += hesap(vecslide[i], vecslide[index-1]);
			new_sco += hesap(vecslide[i], vecslide[index+1]);

			if(new_sco > old_sco){
				swap(vecslide[i], vecslide[index]);
			}
		}	
	}

	for(int i=0; i<size; i++){
		cout << vecslide[i]->p1->index;
		if(vecslide[i]->p2){
			cout << " " << vecslide[i]->p2->index;
		}
		cout << endl;
	}

	cerr << "end loop" << endl;
	return 0;
}