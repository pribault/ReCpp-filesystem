#include <recpp/filesystem/FileSystem.h>
#include <recpp/async/ThreadPool.h>
#include <recpp/async/EventLoop.h>

#include <iostream>

int main()
{
	recpp::async::ThreadPool threadPool;
	recpp::async::EventLoop eventLoop;
	recpp::filesystem::FileSystem fileSystem(threadPool);

	fileSystem.rxAbsolute("examples")
		.subscribe(
			[&eventLoop](const auto &result)
			{
				std::cout << "result=" << result << std::endl;
				eventLoop.stop();
			});

	eventLoop.run();
	return EXIT_SUCCESS;
}
