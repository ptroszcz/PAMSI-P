#include "Board.hh"



void Path::Display() {
  if (Capture)
    std::cout<<"Bicie:"<<std::endl;
  else
    std::cout<<"Ruch:"<<std::endl;
  for (auto it=pathvec.begin();it!=pathvec.end();++it) 
    std::cout<<it->x1<<it->y1<<" ->  "<<it->x2<<it->y2<<std::endl;
}

void Board::init() {
  for (int i=0;i<8;++i){
    for (int j=0;j<8;++j) {
      if (i==3 || i==4 || (i%2==j%2))
	board(i,j)=0;
      else {
	if (i<3)
	  board(i,j)=1;
	else
	  board(i,j)=-1;
      }
    }
  }
}


bool Board::MoveBlack(int x1, int y1, int x2, int y2) {
  if ( board(x1,y1)<=0) {
    return false;
  }
  else if (board(x2,y2)!=0) {
    return false; }
  else if (board(x1,y1)==1) {
    if (x2==x1+1 && (y2==y1+1  || y2==y1-1)) {
      board(x1,y1)=0;
      if (x2==7) {
	board(x2,y2)=2;
      }
      else
	board(x2,y2)=1;
      return true;
    } 
  }
  else {
    if ((abs(x2-x1)) == (abs(y2-y1))) {
      if (y1>y2) {
	if (x1>x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1-i,y1-i)!=0)
	      return false;
	  }
	}
	if (x1<x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1+i,y1-i)!=0)
	      return false;
	  }
	}
      }
      else {
	if (x1>x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1-i,y1+i)!=0)
	      return false;
	  }
	}
	if (x1<x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1+i,y1+i)!=0)
	      return false;
	  }
	}
      }
      board(x1,y1)=0;
      board(x2,y2)=2;
    }
    return true;
  }
  return false;
}

bool Board::MoveWhite(int x1, int y1, int x2, int y2) {
  if ( board(x1,y1)>=0) {
    return false;
  }
  else if (board(x2,y2)!=0) {
    return false; }
  else if (board(x1,y1)==-1) {
    if (x2==x1-1 && (y2==y1+1  || y2==y1-1)) {
      board(x1,y1)=0;
      if (x2==0) {
	board(x2,y2)=-2;
      }
      else
	board(x2,y2)=-1;
      return true;
    } 
  }
  else {
    if ((abs(x2-x1)) == (abs(y2-y1))) {
      if (y1>y2) {
	if (x1>x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1-i,y1-i)!=0)
	      return false;
	  }
	}
	if (x1<x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1+i,y1-i)!=0)
	      return false;
	  }
	}
      }
      else {
	if (x1>x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1-i,y1+i)!=0)
	      return false;
	  }
	}
	if (x1<x2) {
	  for (int i=1;i<abs(x2-x1);++i) {
	    if (board(x1+i,y1+i)!=0)
	      return false;
	  }
	}
      }
      board(x1,y1)=0;
      board(x2,y2)=-2;
    }
    return true;
  }
  return false;
}

bool Board::CheckCaptureBlack(int x, int y) {
  if (board(x,y)<=0)
    return false;
  else if (board(x,y)==1) {
    if (y>1) {
      if (x>1 && board(x-1,y-1)<0 && board(x-2,y-2)==0)
	return true;
      if (x<6 && board(x+1,y-1)<0 && board(x+2,y-2)==0)
	return true;
    }
    if (y<6) {
      if (x>1 && board(x-1,y+1)<0 && board(x-2,y+2)==0)
	return true;
      if (x<6 && board(x+1,y+1)<0 && board(x+2,y+2)==0)
	return true;
    }
  }
  else {
    if (y>1) {
      if (x>1) {
	for (int i=1;(x-i)>0 && (y-i)>0;++i) {
	  if (board(x-i,y-i)>0)
	    break;
	  if (board(x-i,y-i)<0) {
	    if (board(x-i-1,y-i-1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
      if (x<6) {
	for (int i=1;(x+i)<7 && (y-i)>0;++i) {
	  if (board(x+i,y-i)>0)
	    break;
	  if (board(x+i,y-i)<0) {
	    if (board(x+i+1,y-i-1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
    }
    if (y<6) {
      if (x>1) {
	for (int i=1;(x-i)>0 && (y+i)<7;++i) {
	  if (board(x-i,y+i)>0)
	    break;
	  if (board(x-i,y+i)<0) {
	    if (board(x-i-1,y+i+1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
      if (x<6) {
	for (int i=1;(x+i)<7 && (y+i)<7;++i) {
	  if (board(x+i,y+i)>0)
	    break;
	  if (board(x+i,y+i)<0) {
	    if (board(x+i+1,y+i+1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
    }	  
  }
  return false;
}

bool Board::CheckCaptureWhite(int x, int y) {
  if (board(x,y)>=0)
    return false;
  else if (board(x,y)==-1) {
    if (y>1) {
      if (x>1 && board(x-1,y-1)>0 && board(x-2,y-2)==0)
	return true;
      if (x<6 && board(x+1,y-1)>0 && board(x+2,y-2)==0)
	return true;
    }
    if (y<6) {
      if (x>1 && board(x-1,y+1)>0 && board(x-2,y+2)==0)
	return true;
      if (x<6 && board(x+1,y+1)>0 && board(x+2,y+2)==0)
	return true;
    }
  }
  else {
    if (y>1) {
      if (x>1) {
	for (int i=1;(x-i)>0 && (y-i)>0;++i) {
	  if (board(x-i,y-i)<0)
	    break;
	  if (board(x-i,y-i)>0) {
	    if (board(x-i-1,y-i-1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
      if (x<6) {
	for (int i=1;(x+i)<7 && (y-i)>0;++i) {
	  if (board(x+i,y-i)<0)
	    break;
	  if (board(x+i,y-i)>0) {
	    if (board(x+i+1,y-i-1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
    }
    if (y<6) {
      if (x>1) {
	for (int i=1;(x-i)>0 && (y+i)<7;++i) {
	  if (board(x-i,y+i)<0)
	    break;
	  if (board(x-i,y+i)>0) {
	    if (board(x-i-1,y+i+1)==0)
	      return true;
	    else
	      break;
	  }
	}
      }
      if (x<6) {
	for (int i=1;(x+i)<7 && (y+i)<7;++i) {
	  if (board(x+i,y+i)<0)
	    break;
	  if (board(x+i,y+i)>0) {
	    if (board(x+i+1,y+i+1)==0)
	      return true;
	    else
	      break;
	  }	  
	}
      }	  
    }
  }
  return false;
}


bool Board::CheckCaptureBlack(int x1, int y1, int x2, int y2){
  if(!CheckCaptureBlack(x1,y1) || abs(x2-x1)<2 || abs(y2-y1)<2 || board(x2,y2)!=0)
    return false;
  if (board(x1,y1)==1) {
    if (board((x1+x2)/2,(y1+y2)/2)<0 && abs(x2-x1)==2 && abs(y2-y1)==2){
      return true;
    }
    else
      return false;
  }
  else {
     if ((abs(x2-x1)) == (abs(y2-y1))) {
       int i,j;
       if (x2>x1)
	 i=1;
       else
	 i=-1;
       if (y2>y1)
	 j=1;
       else
	 j=-1;
       int helpx=x1;
       int helpy=y1;
       int count=0;
       while(helpx!=x2  && count < 2) {
	 helpx+=i;
	 helpy+=j;
	 if (board(helpx,helpy)>0)
	   return false;
	 if (board(helpx,helpy)<0) {
	   count++; }
       }
       if (count==1) {
	 return true; }
       else
	 return false;
     }
  }
  return false;
}


bool Board::CheckCaptureWhite(int x1, int y1, int x2, int y2){
  if(!CheckCaptureWhite(x1,y1) || abs(x2-x1)<2 || abs(y2-y1)<2 || board(x2,y2)!=0)
    return false;
  if (board(x1,y1)==-1) {
    if (board((x1+x2)/2,(y1+y2)/2)>0 && abs(x2-x1)==2 && abs(y2-y1)==2){
      return true;
    }
    else
      return false;
  }
  else {
     if ((abs(x2-x1)) == (abs(y2-y1))) {
       int i,j;
       if (x2>x1)
	 i=1;
       else
	 i=-1;
       if (y2>y1)
	 j=1;
       else
	 j=-1;
       int helpx=x1;
       int helpy=y1;
       int count=0;
       while(helpx!=x2  && count < 2) {
	 helpx+=i;
	 helpy+=j;
	 if (board(helpx,helpy)<0)
	   return false;
	 if (board(helpx,helpy)>0) {
	   count++; }
       }
       if (count==1) {
	 return true; }
       else
	 return false;
     }
  }
  return false;
}

bool Board::AnyCaptureBlack() {
  for (int i=0;i<8;++i){
    for (int j=0;j<8;++j){
      if (board(i,j)>0) {
	if (CheckCaptureBlack(i,j))
	  return true;
      }
    }
  }
  return false;
}

bool Board::AnyCaptureWhite() {
  for (int i=0;i<8;++i){
    for (int j=0;j<8;++j){
      if (board(i,j)<0) {
	if (CheckCaptureWhite(i,j))
	  return true;
      }
    }
  }
  return false;
}

bool Board::CaptureBlack(int x1, int y1, int x2, int y2){
  if (!CheckCaptureBlack(x1,y1,x2,y2))
    return false;
  else if (board(x1,y1)==1) {
    board((x1+x2)/2,(y1+y2)/2)=0;
    board(x1,y1)=0;
    board(x2,y2)=1;
    if (x2==7 && !CheckCaptureBlack(x2,y2))
      board(x2,y2)=2;
    return true;
  }
  else {
    int i,j;
    if (x2>x1)
      i=1;
    else
      i=-1;
    if (y2>y1)
      j=1;
    else
      j=-1;
    int helpx=x1;
    int helpy=y1;
    int todelete;
    int count=0;
    while(count==0) {
      helpx+=i;
      helpy+=j;
      if (board(helpx,helpy)<0) {
	todelete=helpx*10+helpy;
	count++; }
    }
    board(x1,y1)=0;
    board(todelete/10,todelete%10)=0;
    board(x2,y2)=2;
    return true; 
  }
  return false;
}


bool Board::CaptureWhite(int x1, int y1, int x2, int y2){
  if (!CheckCaptureWhite(x1,y1,x2,y2))
    return false;
  else if (board(x1,y1)==-1) {
    board((x1+x2)/2,(y1+y2)/2)=0;
    board(x1,y1)=0;
    board(x2,y2)=-1;
    if (x2==0 && !CheckCaptureWhite(x2,y2))
      board(x2,y2)=-2;
    return true;
  }
  else {
    int i,j;
    if (x2>x1)
      i=1;
    else
      i=-1;
    if (y2>y1)
      j=1;
    else
      j=-1;
    int helpx=x1;
    int helpy=y1;
    int todelete;
    int count=0;
    while(count==0) {
      helpx+=i;
      helpy+=j;
      if (board(helpx,helpy)>0) {
	todelete=helpx*10+helpy;
	count++; }
    }
    board(x1,y1)=0;
    board(todelete/10,todelete%10)=0;
    board(x2,y2)=-2;
    return true; 
  }
  return false;
}

void Board::BackBoard(std::vector<std::vector<int>> back){
  for (auto it=back.begin();it!=back.end();++it)
    board((*it)[0],(*it)[1])=(*it)[2];
}

/*funkcja zakłada podanie poprawnych koordynatów dla bicia*/
std::vector<std::vector<int>> Board::CaptureCopy(int x1, int y1, int x2, int y2) {
  std::vector<std::vector<int>> back;
  std::vector<int> help;
  help.push_back(x1);
  help.push_back(y1);
  help.push_back(board(x1,y1));
  back.push_back(help);
  help.clear();
  if (board(x1,y1) == 1 || board(x1,y1)==-1) {
    help.push_back((x1+x2)/2);
    help.push_back((y1+y2)/2);
    help.push_back(board((x1+x2)/2,(y1+y2)/2));
    back.push_back(help);
    help.clear();
  }
  else {
    int i,j;
    if (x2>x1)
      i=1;
    else
      i=-1;
    if (y2>y1)
      j=1;
    else
      j=-1;
    int helpx=x1+i;
    int helpy=y1+j;
    int found=0;
    while(found==0 && helpx>=0 && helpx<=7 && helpy>=0 && helpy<=7) {
      if (board(helpx,helpy)!=0) {
	 help.push_back(helpx);
	 help.push_back(helpy);
	 help.push_back(board(helpx,helpy));
	 back.push_back(help);
	 found++; } 
      helpx+=i;
      helpy+=j;
    }
    help.clear();
  }
  help.push_back(x2);
  help.push_back(y2);
  help.push_back(board(x2,y2));
  back.push_back(help);
    
  return back;
}

std::vector<std::vector<int>> Board::PossibleBlackCapture(int i, int j){
  std::vector<std::vector<int>> result;
  if (CheckCaptureBlack(i,j)){
    std::vector<int> help;
    if (board(i,j)==1) {
      if ((i-2)>=0) {
	if ((j-2)>=0 && CheckCaptureBlack(i,j,i-2,j-2)){
	  help.push_back(i-2);
	  help.push_back(j-2);
	  result.push_back(help);
	  help.clear();
	}
	if ((j+2)<=7 && CheckCaptureBlack(i,j,i-2,j+2)) {
	  help.push_back(i-2);
	  help.push_back(j+2);
	  result.push_back(help);
	  help.clear();
	}
      }
      if ((i+2)<=7) {
	if ((j-2)>=0 && CheckCaptureBlack(i,j,i+2,j-2)){
	  help.push_back(i+2);
	  help.push_back(j-2);
	  result.push_back(help);
	  help.clear();
	}
	if ((j+2)<=7 && CheckCaptureBlack(i,j,i+2,j+2)) {
	  help.push_back(i+2);
	  help.push_back(j+2);
	  result.push_back(help);
	  help.clear();
	}
      }
    }
    else {
      int help1=1;
      while (i-help1>=0 && j-help1>=0 && board(i-help1,j-help1)<=0) {
	if (CheckCaptureBlack(i,j,i-help1,j-help1)) {
	  help.push_back(i-help1);
	  help.push_back(j-help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
      help1=1;
      while (i+help1<=7 && j-help1>=0 && board(i+help1,j-help1)<=0) {
	if (CheckCaptureBlack(i,j,i+help1,j-help1)) {
	  help.push_back(i+help1);
	  help.push_back(j-help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
      help1=1;
      while (i+help1<=7 && j+help1<=7 && board(i+help1,j+help1)<=0) {
	if (CheckCaptureBlack(i,j,i+help1,j+help1)) {
	  help.push_back(i+help1);
	  help.push_back(j+help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
      help1=1;
      while (i-help1>=0 && j+help1<=7 && board(i-help1,j+help1)<=0) {
	if (CheckCaptureBlack(i,j,i-help1,j+help1)) {
	  help.push_back(i-help1);
	  help.push_back(j+help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
    }
  }
  return result;
}

std::vector<std::vector<int>> Board::PossibleWhiteCapture(int i, int j){
  std::vector<std::vector<int>> result;
  if (CheckCaptureWhite(i,j)){
    std::vector<int> help;
    if (board(i,j)==-1) {
      if ((i-2)>=0) {
	if ((j-2)>=0 && CheckCaptureWhite(i,j,i-2,j-2)){
	  help.push_back(i-2);
	  help.push_back(j-2);
	  result.push_back(help);
	  help.clear();
	}
	if ((j+2)<=7 && CheckCaptureWhite(i,j,i-2,j+2)) {
	  help.push_back(i-2);
	  help.push_back(j+2);
	  result.push_back(help);
	  help.clear();
	}
      }
      if ((i+2)<=7) {
	if ((j-2)>=0 && CheckCaptureWhite(i,j,i+2,j-2)){
	  help.push_back(i+2);
	  help.push_back(j-2);
	  result.push_back(help);
	  help.clear();
	}
	if ((j+2)<=7 && CheckCaptureWhite(i,j,i+2,j+2)) {
	  help.push_back(i+2);
	  help.push_back(j+2);
	  result.push_back(help);
	  help.clear();
	}
      }
    }
    else {
      int help1=1;
      while (i-help1>=0 && j-help1>=0 && board(i-help1,j-help1)>=0) {
	if (CheckCaptureWhite(i,j,i-help1,j-help1)) {
	  help.push_back(i-help1);
	  help.push_back(j-help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
      help1=1;
      while (i+help1<=7 && j-help1>=0 && board(i+help1,j-help1)>=0) {
	if (CheckCaptureWhite(i,j,i+help1,j-help1)) {
	  help.push_back(i+help1);
	  help.push_back(j-help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
      help1=1;
      while (i+help1<=7 && j+help1<=7 && board(i+help1,j+help1)>=0) {
	if (CheckCaptureWhite(i,j,i+help1,j+help1)) {
	  help.push_back(i+help1);
	  help.push_back(j+help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
      help1=1;
      while (i-help1>=0 && j+help1<=7 && board(i-help1,j+help1)>=0) {
	if (CheckCaptureWhite(i,j,i-help1,j+help1)) {
	  help.push_back(i-help1);
	  help.push_back(j+help1);
	  result.push_back(help);
	  help.clear(); }
	help1++;
      }
    }
  }
  return result;
}

std::vector<Path> Board::PossibleBlack() {
  std::vector<Path> moves;
  if (!AnyCaptureBlack()) {
    for (int i=0;i<8;++i) {
      for (int j=0;j<8;++j) {
	if (board(i,j)==1) {
	  if (j>0 && board(i+1,j-1)==0) {
	    Path pathm;
	    MoveCo move(i,j,i+1,j-1);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	  }
	  if (j<7 && board(i+1,j+1)==0) {
	    Path pathm;
	    MoveCo move(i,j,i+1,j+1);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	  }
	}
	else if (board(i,j)==2) {
	  int help=1;
	  while (i-help>=0 && j-help>=0 && board(i-help,j-help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i-help,j-help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	  help=1;
	  while (i+help<=7 && j-help>=0 && board(i+help,j-help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i+help,j-help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	  help=1;
	  while (i+help<=7 && j+help<=7 && board(i+help,j+help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i+help,j+help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	  help=1;
	  while (i-help>=0 && j+help<=7 && board(i-help,j+help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i-help,j+help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	}
      }
    }
  }
  else {
    for (int i=0;i<8;++i) {
      for (int j=0;j<8;++j) {
	std::vector<Path> help;
	if (CheckCaptureBlack(i,j)) {
	  help=MultipleCaptureBlack(i,j);
	  for (auto it=help.begin();it!=help.end();++it)
	    moves.push_back(*it);
	}
      }
    }
  }
  return moves;
}

std::vector<Path> Board::MultipleCaptureBlack(int x, int y) {
  std::vector<Path> result;
  if (!CheckCaptureBlack(x,y))
    return result;
  else {
    std::vector<std::vector<int>> help;
    help=PossibleBlackCapture(x,y);
    for (auto it=help.begin();it!=help.end();++it) {
      Path pathm;
      pathm.Capture=true;
      MoveCo move(x,y,(*it)[0],(*it)[1]);
      pathm.pathvec.push_back(move);
      std::vector<std::vector<int>> copy=CaptureCopy(x,y,(*it)[0],(*it)[1]);
      int check=board(x,y); /*sprawdza czy pionek nie stal sie damka*/
      CaptureBlack(x,y,(*it)[0],(*it)[1]);
      if (CheckCaptureBlack((*it)[0],(*it)[1]) && check==board((*it)[0],(*it)[1])) {
	std::vector<Path> temp=MultipleCaptureBlack((*it)[0],(*it)[1]);
	for (auto iter=temp.begin();iter!=temp.end();iter++) {
	  Path tpath=pathm;
	  for (auto iterator=(iter->pathvec).begin();iterator!=(iter->pathvec).end();++iterator) {
	    move=*iterator;
	    tpath.pathvec.push_back(move);
	  }
	    result.push_back(tpath);
	}
      }
      else
	result.push_back(pathm);
      BackBoard(copy);
    }
  }
  return result;
}

std::vector<Path> Board::MultipleCaptureWhite(int x, int y) {
  std::vector<Path> result;
  if (!CheckCaptureWhite(x,y))
    return result;
  else {
    std::vector<std::vector<int>> help;
    help=PossibleWhiteCapture(x,y);
    for (auto it=help.begin();it!=help.end();++it) {
      Path pathm;
      pathm.Capture=true;
      MoveCo move(x,y,(*it)[0],(*it)[1]);
      pathm.pathvec.push_back(move);
      std::vector<std::vector<int>> copy=CaptureCopy(x,y,(*it)[0],(*it)[1]);
      int check=board(x,y); /*sprawdzenie czy pionek nie stal sie damka*/
      CaptureWhite(x,y,(*it)[0],(*it)[1]);
      if (CheckCaptureWhite((*it)[0],(*it)[1]) && check==board((*it)[0],(*it)[1])) {
	std::vector<Path> temp=MultipleCaptureWhite((*it)[0],(*it)[1]);
	for (auto iter=temp.begin();iter!=temp.end();iter++) {
	  Path tpath=pathm;
	  for (auto iterator=(iter->pathvec).begin();iterator!=(iter->pathvec).end();++iterator) {
	    move=*iterator;
	    tpath.pathvec.push_back(move);
	  }
	    result.push_back(tpath);
	}
      }
      else
	result.push_back(pathm);
      BackBoard(copy);
    }
  }
  return result;
}


std::vector<Path> Board::PossibleWhite() {
  std::vector<Path> moves;
  if (!AnyCaptureWhite()) {
    for (int i=0;i<8;++i) {
      for (int j=0;j<8;++j) {
	if (board(i,j)==-1) {
	  if (j>0 && board(i-1,j-1)==0) {
	    Path pathm;
	    MoveCo move(i,j,i-1,j-1);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	  }
	  if (j<7 && board(i-1,j+1)==0) {
	    Path pathm;
	    MoveCo move(i,j,i-1,j+1);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	  }
	}
	else if (board(i,j)==-2) {
	  int help=1;
	  while (i-help>=0 && j-help>=0 && board(i-help,j-help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i-help,j-help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	  help=1;
	  while (i+help<=7 && j-help>=0 && board(i+help,j-help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i+help,j-help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	  help=1;
	  while (i+help<=7 && j+help<=7 && board(i+help,j+help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i+help,j+help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	  help=1;
	  while (i-help>=0 && j+help<=7 && board(i-help,j+help)==0) {
	    Path pathm;
	    MoveCo move(i,j,i-help,j+help);
	    pathm.pathvec.push_back(move);
	    pathm.Capture = false;
	    moves.push_back(pathm);
	    help++;
	  }
	}
      }
    }
  }
  else {
    for (int i=0;i<8;++i) {
      for (int j=0;j<8;++j) {
	std::vector<Path> help;
	if (CheckCaptureWhite(i,j)) {
	  help=MultipleCaptureWhite(i,j);
	  for (auto it=help.begin();it!=help.end();++it)
	    moves.push_back(*it);
	}
      }
    }
  }
  return moves;
}


std::vector<std::vector<int>> Board::Move(Path road, bool white) {
  std::vector<std::vector<int>> back;
  if (!road.Capture) {
    std::vector<int> help;
    MoveCo coords=road.pathvec[0];
    help.push_back(coords.x1);
    help.push_back(coords.y1);
    help.push_back(board(coords.x1,coords.y1));
    back.push_back(help);
    help.clear();
    help.push_back(coords.x2);
    help.push_back(coords.y2);
    help.push_back(board(coords.x2,coords.y2));
    back.push_back(help);
    if (white)
      MoveWhite(coords.x1,coords.y1,coords.x2,coords.y2);
    else
      MoveBlack(coords.x1,coords.y1,coords.x2,coords.y2);
  }
  else {
    for (auto it=road.pathvec.begin();it!=road.pathvec.end();++it) {
      std::vector<std::vector<int>> copy=CaptureCopy(it->x1,it->y1,it->x2,it->y2);
      back.insert(back.begin(),copy.begin(),copy.end());
      if (white)
	CaptureWhite(it->x1,it->y1,it->x2,it->y2);
      else
	CaptureBlack(it->x1,it->y1,it->x2,it->y2);
    }
  }
  return back;
}

/*Wartość dodatnia oznacza przewagę czarnych zaś wartość ujemna - przewagę białych*/
int Board::Calculate() {
  int value=0;
  for (int i=0;i<8;++i) {
    for (int j=0;j<8;++j) {
      switch(board(i,j)){
      case 1:
	value++;
	if (i==5 || i==6)
	  value++;
	break;
      case 2:
	value+=4;
	break;
      case -1:
	value--;
	if (i==1 || i==2)
	  value--;
	break;
      case -2:
	value-=4;
	break;
      default:
	break;
      }
    }
  }
  return value;
}
	      
