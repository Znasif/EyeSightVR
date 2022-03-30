using UnrealBuildTool;
using System.IO;

public class UEOpenCV: ModuleRules
{
    private string ThirdPartyPath
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/"));
        }
    }
    public UEOpenCV(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

        LoadOpenCV(Target);
    }

	public bool LoadOpenCV(ReadOnlyTargetRules Target)
	{
		bool isLibrarySupported = false;
		string OpenCVPath = Path.Combine(ThirdPartyPath, "OpenCV");

		string LibPath = Path.Combine(OpenCVPath, "Libraries", "Win64");

		//Add Include path
		PublicIncludePaths.AddRange(new string[] { Path.Combine(OpenCVPath, "Includes") });

		//Add Static Libraries
		PublicAdditionalLibraries.Add(Path.Combine(LibPath, "opencv_world454.lib"));

		//Add Dynamic Libraries
		PublicDelayLoadDLLs.Add(Path.Combine(LibPath, "opencv_world454.dll"));
		RuntimeDependencies.Add("$(TargetOutputDir)/opencv_world454.dll", Path.Combine(LibPath, "opencv_world454.dll"));
		PublicDelayLoadDLLs.Add(Path.Combine(LibPath, "opencv_videoio_ffmpeg454_64.dll"));
		RuntimeDependencies.Add("$(TargetOutputDir)/opencv_videoio_ffmpeg454_64.dll", Path.Combine(LibPath, "opencv_videoio_ffmpeg454_64.dll"));



		PublicDefinitions.Add(string.Format("WITH_OPENCV_BINDING={0}", isLibrarySupported ? 1 : 0));

		return isLibrarySupported;
	}
}