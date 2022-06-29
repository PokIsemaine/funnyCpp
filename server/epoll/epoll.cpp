#include <sys/epoll.h>


// https://www.bookstack.cn/read/libevent/ab15710b52bbdef1.md


int main() {
	
	//创建 epoll
	int epfd = epoll_create(1000);

	//将 listen_fd 添加进 epoll 中
	epoll_ctl(epfd,EPOLL_CTL_ADD,listen_fd, &listen_event);

	for(;;) {
		// 阻塞等待 epoll 中 fd 触发 , -1 表示永久阻塞
		int active_cnt = epoll_wait(epfd, events, 1000, -1);

		for(int i = 0; i < active_cnt ; ++i) {
			if(events[i].data.fd == listen_fd) {
				//accept. 并且将新accept 的fd 加进epoll中.
			} else if ( events[i].events & EPOLLIN) {
				//对此fd 进行 读操作
			} else if (events[i].events & EPOLLOUT) {
				//对此fd 进行 读操作
			}
		}
	}
	
	return 0;
}