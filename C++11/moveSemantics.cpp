/*
- Rule of three(Prior to c++11)- copy ctor, copy assignment and destructor
- Rule of five - Rule of three, move ctor, move assignment
- So, when is the compiler allowed to move objects instead of copying? As a short answer, the
compiler moves an object when the object can be categorized as an r-value. The term rvalue might sound complicated, but in essence it is just an object which is not tied to a
named variable, for either of the following reasons:
	1. It's coming straight out of a function
	2. We make a variable an r-value by using std::move(...)
 
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class buffer
{
public:
	auto begin() const {
		return _ptr;
	}

	auto end() const {
		return _ptr+_size;
	}

	buffer(const initializer_list<float>& values) : _size{values.size()} {
		cout<<"Buffer ctor"<<endl;
		_ptr = new float[_size];
		copy(values.begin(), values.end(), _ptr);
	}

	void showData() {
		for(int i=0; i<_size; i++)
			cout<<_ptr[i]<<" ";
		cout<<endl;
	}
	
	buffer(const buffer& other) : _size{other._size} {
		cout<<"Copy ctor"<<endl;
		_ptr = new float[_size];
		copy(other._ptr, other._ptr + _size, _ptr);
	}

	auto operator=(const buffer& other) -> buffer& {
		cout<<"Assignment operator"<<endl;
		delete[] _ptr;
		_size = other._size;
		_ptr = new float[_size];
		copy(other.begin(), other.end(), _ptr);
		return *this;
	}

	buffer(buffer&& other) noexcept 
		: _ptr(other.begin()), _size(other._size) 
	{
		cout<<"Move ctor"<<endl;
		other._ptr=nullptr;
		other._size=0;
	}

	auto operator=(buffer&& other) noexcept {
		cout<<"Move assignment"<<endl;
		_ptr = other._ptr;
		_size = other._size;
		other._ptr = nullptr;
		other._size = 0;
		return *this;
	}

	~buffer() {
		delete[] _ptr;
		_ptr = nullptr;
	}

private:
	size_t _size{0};
	float* _ptr{nullptr};
};

class Bird
{
public:
	void setSong(const string& s) { _song = s; }
	void setSong(string&& s) { _song = move(s); }
private:
	string _song;
};

class TowerList
{
public:
	TowerList() : max_height_idx{2}, tower_height{1.2, 2.2, 3.3} 
	{
		cout<<"TowerList ctor"<<endl;
	}
	auto get_max_height_val() const {
		return max_height_idx >= 0 ?
			tower_height[max_height_idx] : 0.0f;
	}
	TowerList(TowerList&& other) noexcept {
		cout<<"TowerList move ctor"<<endl;
		std::swap(other.max_height_idx, max_height_idx);
		std::swap(other.tower_height, tower_height);
	}
private:
	vector<float> tower_height{};
	int max_height_idx{-1};
};

class foo
{
public:
	auto func() && {  }
};
	auto a = foo{};
	//a.func(); // Does not compile, 'a' is not an r-value

auto  make_buffer() 
{
	auto local_buffer = buffer({5.0,4.6});
	cout<<"Inside make_buffer"<<endl;
	local_buffer.showData();
	return local_buffer;
}

auto make_roast_song()
{
	return string("I'm a roast");
}

auto str_to_lower(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

int main()
{
	auto float_array = buffer({1.0, 2.0});
	float_array.showData();
	
	auto float_array_2 = float_array;
	float_array_2.showData();	
	
	float_array = float_array_2;
	float_array.showData();
	
	auto float_buf = make_buffer();
	float_buf.showData();

	//Named variable vs r-value
	auto bird = Bird{};
	string cuckoo = "I'm a Cuckoo";

	//Copy-assignment as the song is tied to a variable	
	bird.setSong(cuckoo);
	//Move-assignment as the cuckoo variable is passed through std::move()
	bird.setSong(move(cuckoo));
	//Move-assignment as string is coming straight out of a function
	bird.setSong(make_roast_song());
	
	auto roast_song = make_roast_song();
	//Copy-assignment as the song string is held by roast_song variable
	bird.setSong(roast_song);

	const auto roast_song_b = make_roast_song();
	//copy-assigned as roast_song_b is declared const, and thus not allowed to mutate
	bird.setSong(roast_song_b);

	auto str = string{"ABC"};
	cout<<str_to_lower(str)<<endl;
	cout<<str_to_lower(move(str))<<endl;
	
	//Move semantic - Pit fall
	cout<<"Move sematic- Pit fall"<<endl;
	TowerList t1;
	cout<<t1.get_max_height_val()<<endl;
	auto t2 = std::move(t1);
	cout<<t1.get_max_height_val()<<endl;;

	//&& modifier to class member functions
	cout<<"&& modifier to class member functions"<<endl;
	//auto f = foo{};
	//f.func();

	return 0;
}
