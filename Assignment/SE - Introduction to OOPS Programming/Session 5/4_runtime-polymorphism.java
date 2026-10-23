/*
Given this code: 

class MusicPlayer { 
    void play(String song) { 
        System.out.println("Playing: " + song); 
    } 
} 

class SpotifyPlayer extends MusicPlayer { 
    void play(String song) { 
        System.out.println("Streaming on Spotify: " + song); 
    } 
} 

Create an object of type MusicPlayer but assign it a SpotifyPlayer instance, then call play(). Explain the output.
Hint: This tests runtime polymorphism (overriding) and dynamic method dispatch.
*/
class MusicPlayer {
    void play(String song) {
        System.out.println("Playing: " + song);
    }
}

class SpotifyPlayer extends MusicPlayer {
    @Override
    void play(String song) {
        System.out.println("Streaming on Spotify: " + song);
    }
}

// Added code to implement the object creation and method calling
public class Main {
    public static void main(String[] args) {
        MusicPlayer player = new SpotifyPlayer();
        player.play("Enamorado by King ft.Nishant Mukta");
    }
}

/*
Output:
Streaming on Spotify: Enamorado by King ft.Nishant Mukta

Explaination:

*/