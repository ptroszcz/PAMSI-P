#include "Game.hh"

void Game::start() {
  window.create(sf::VideoMode(579,401), "Warcaby");
  textures[0].loadFromFile("board.png");
  textures[1].loadFromFile("pionekc.png");
  textures[2].loadFromFile("pionekb.png");
  textures[3].loadFromFile("damkab.png");
  textures[4].loadFromFile("damkac.png");
  textures[5].loadFromFile("turaC.png");
  textures[6].loadFromFile("turaGB.png");
  textures[7].loadFromFile("turaGN.png");
  textures[8].loadFromFile("WINB.png");
  textures[9].loadFromFile("WINC.png");
  
  sprites[0].setTexture(textures[0]);
  sprites[1].setTexture(textures[1]);
  sprites[2].setTexture(textures[2]);
  sprites[3].setTexture(textures[3]);
  sprites[4].setTexture(textures[4]);
  sprites[5].setTexture(textures[5]);
  sprites[6].setTexture(textures[6]);
  sprites[7].setTexture(textures[7]);
  sprites[8].setTexture(textures[8]);
  sprites[9].setTexture(textures[9]);
  draw();
  sprites[7].setPosition(401,0);
  window.draw(sprites[7]);
  window.display();
  std::vector<double> times;
  std::chrono::high_resolution_clock timer;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    std::vector<Path> white=board.PossibleWhite();
    /*testowanie generowania mozlwych ruchow bialych*/
    /*  std::cout<<"Biale:"<<std::endl;
    for (auto it=white.begin();it!=white.end();++it)
      it->Display();
    draw();
    window.display(); */
    if (white.empty()) {
      draw();
      sprites[9].setPosition(401,0);
      window.draw(sprites[9]);
      window.display();
      while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))){}
      window.close();  }
    else {
      if (board.AnyCaptureWhite()) {
	draw();
	sprites[6].setPosition(401,0);
	window.draw(sprites[6]);
	window.display();
	WhiteCapture();
      }
      else {
	draw();
	sprites[7].setPosition(401,0);
	window.draw(sprites[7]);
	window.display();
	FreeWhite();
      }
     
      usleep(100000);
      std::vector<Path> black=board.PossibleBlack();
      /*testowanie generowania mozliwych ruchow czarnych*/
      /*std::cout<<"Czarne:"<<std::endl;
      for (auto it=black.begin();it!=black.end();++it)
      it->Display();
      draw();
      window.display();*/
      if (black.empty()) {
	draw();
	sprites[8].setPosition(401,0);
	window.draw(sprites[8]);
	window.display();
	while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))){}
	window.close();
      }
      else {
	draw();
	sprites[5].setPosition(401,0);
	window.draw(sprites[5]);
	window.display();
	auto tstart=timer.now();
	Computer(false); /*przekazujemy false jako znak ze ruch czarnych*/
	auto tend=timer.now();
	std::chrono::duration<double> sec=tend-tstart;
	times.push_back(sec.count());
	usleep(100000);
      }
    }
  }
  /*badanie czasu wykonywania algorytmu*/
  auto it=times.begin();
  double summary=0;
  double min=*it;
  double max=*it;
  for (;it!=times.end();++it) {
    if (*it<min)
      min=*it;
    if (*it>max)
      max=*it;
    summary+=*it; }
  std::cout<<"Średni czas potrzebny na ruch sztucznej intelignecji: "<<summary/(times.size())<<std::endl;
  std::cout<<"Maksymalny czas: "<<max<<"  Minimalny czas: "<<min<<std::endl;
    
    
}

void Game::draw() {
   window.clear();
   window.draw(sprites[0]);
   for (int i=0;i<8;++i) {
     for (int j=0;j<8;++j) {
       switch(board(i,j)) {
       case 0:
	 break;
       case 1:
	 sprites[1].setPosition(j*50,i*50);
	 window.draw(sprites[1]);
	 break;
       case -1:
	 sprites[2].setPosition(j*50,i*50);
	 window.draw(sprites[2]);
	 break;
       case -2:
	 sprites[3].setPosition(j*50,i*50);
	 window.draw(sprites[3]);
	 break;
       case 2:
	 sprites[4].setPosition(j*50,i*50);
	 window.draw(sprites[4]);
	 break;
       }
     }
   }
}

bool Game::CheckWindow() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
      return false;
    }
  }
  return true;
}


int Game::mouse() {
  sf::Vector2i mousep;
  int pos=-1;
  int isPressed=0;
  while(isPressed==0){
    if (!window.isOpen())
      break;
    if (!CheckWindow())
      break;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      mousep=sf::Mouse::getPosition(window);
      if (mousep.x>0 && mousep.x<401 && mousep.y>0 && mousep.y<401) {
	mousep.x=mousep.x/50;
	mousep.y=mousep.y/50;
	pos=mousep.x*10+mousep.y;
	isPressed=1;
      }
    }
  }
  return pos;
}


void Game::FreeBlack() {
  int one, two;
  int correct=0;
  while (correct==0) {
    one=mouse();
    two=mouse();
    if (one==-1 || two==-1)
      break;
    while (two==one && two!=-1)
      two=mouse();
    if (board.MoveBlack(one%10,one/10,two%10,two/10))
      correct=1;
  }
}

void Game::FreeWhite() {
  int one, two;
  int correct=0;
  while (correct==0) {
    one=mouse();
    two=mouse();
    if (one==-1 || two==-1)
      correct=1;
    while (two==one && two!=-1)
      two=mouse();
    if (board.MoveWhite(one%10,one/10,two%10,two/10))
      correct=1;
  }
}

void Game::BlackCapture() {
  int one, two;
  int correct=0;
  while (correct==0) {
    one=mouse();
    two=mouse();
    if (one==-1 || two==-1)
      correct=1;
    while (two==one && two!=-1)
      two=mouse();
    int help=board(one%10,one/10);
    if (board.CaptureBlack(one%10,one/10,two%10,two/10)) {
      draw();
      window.display();
      if (!(help==1  &&  board(two%10,two/10)==2)) {
	while (board.CheckCaptureBlack(two%10,two/10)) {
	  help=board(two%10,two/10);
	  one=mouse();
	  if (one==-1)
	    break;
	  if (board.CaptureBlack(two%10,two/10,one%10,one/10)) {
	    draw();
	    window.display();
	    two=one;
	    if (help==1  &&  board(one%10,one/10)==2)
	      break;
	  }
	}
      }
      correct=1;
    }
  }
}

void Game::WhiteCapture() {
  int one, two;
  int correct=0;
  while (correct==0) {
    one=mouse();
    two=mouse();
    if (one==-1 || two==-1)
      correct=1;
    while (two==one && two!=-1)
      two=mouse();
    int help=board(one%10,one/10);
    if (board.CaptureWhite(one%10,one/10,two%10,two/10)) {
      draw();
      window.display();
      if (!(help==-1  &&  board(two%10,two/10)==-2)) {
	while (board.CheckCaptureWhite(two%10,two/10)) {
	  one=mouse();
	  if (one==-1)
	    break;
	  if (board.CaptureWhite(two%10,two/10,one%10,one/10)) {
	    draw();
	    sprites[6].setPosition(401,0);
	    window.draw(sprites[6]);
	    window.display();
	    window.display();
	    two=one;
	    if (help==-1  &&  board(one%10,one/10)==-2)
	      break;
	  }
	}
      }
      correct=1;
    }
  }
}


void Game::Computer(bool white) {
  std::vector<Path> list;
  if (!white)
    list=board.PossibleBlack();
  else
    list=board.PossibleWhite();
  /*głobokość tworzonego drzewa*/
  int depth=6;
  auto itbest=list.begin();
  int value;
  if (white)
    value=INT_MAX;
  else
    value=std::numeric_limits<int>::min();
  for (auto it=list.begin();it!=list.end();++it) {
    std::vector<std::vector<int>> back;
    back=board.Move(*it,white);
    int var=minmax(depth-1,!white);
    if ((!white && var>value) || (white && var<value)) {
      value=var;
      itbest=it;
    }
    board.BackBoard(back);
    
  }
  board.Move(*itbest,white);
  /*w celach spawdzenia poprawności ruchow komputera*/
  /*std::cout<<"Ruch komputera(format wierszy i kolumn jak w macierzy):"<<std::endl;
  for (auto it=(*itbest).pathvec.begin(); it!=(*itbest).pathvec.end();++it) {
  std::cout<<it->x1<<it->y1<<" -> "<<it->x2<<it->y2<<std::endl; } */
}

int Game::minmax(int depth, bool white){
  int result;
  if (depth==0)
    result=board.Calculate();
  else {
    std::vector<Path> list;
    if (white) {
      list=board.PossibleWhite();
      result=INT_MAX;
      if (list.empty()) 
	return result; 
    }
    else {
      list=board.PossibleBlack();
      result=std::numeric_limits<int>::min();
      if (list.empty()) 
	return result; 
    }
    for (auto it=list.begin();it!=list.end();++it) {
      std::vector<std::vector<int>> back;
      back=board.Move(*it,white);
      int var=minmax(depth-1,!white);
      if ((!white && var>result) || (white && var<result)) 
	result=var;
      board.BackBoard(back);
    }
  }
  return result;
}
